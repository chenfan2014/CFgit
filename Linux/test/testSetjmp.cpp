#include <iostream>
#include <string>
#include <vector>
#include <setjmp.h>
using namespace std;

const int TOK_ADD = 5;
const int MAXLINE = 4096;

jmp_buf jmpBuffer;      //这个是某种形式的数组，其存放在调用longjmp的时候能用来恢复栈状态的所有信息

/*
 *setjmp函数是在我们希望返回到的位置进行调用，这里我们希望如果出错返回到我们的main函数
 *所以我们在main函数中写入我们的setjmp函数
 */

void doLine(char *);
void cmdAdd();
int getToken();

int main(int argc, const char *argv[])
{
    char line[MAXLINE];

    if(setjmp(jmpBuffer) != 0){
        cerr << "error " << endl;
    }

    while(fgets(line, MAXLINE, stdin) != NULL){
        doLine(line);
    }
    return 0;
}

char *tokPtr;
void doLine(char *ptr){
    int cmd;
    tokPtr = ptr;
    while((cmd = getToken()) > 0){
        switch(cmd){
            case TOK_ADD:
                cmdAdd();
                break;
        }
    }
}

void cmdAdd(){
    int token;
    token = getToken();
    if(token < 0){
        longjmp(jmpBuffer, 1);
    }
}

int getToken(){

}
