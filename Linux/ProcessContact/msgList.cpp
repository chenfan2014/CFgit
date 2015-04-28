#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

const int LEN = 64;



struct MSG{
    long mtype;
    char buf[LEN];
};

int main(int argc, const char *argv[])
{
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);  //创建消息队列
    if(msgid == -1){
        ERR_EXIT("wrong msggid");
    }
    MSG msg;
    memset(&msg, 0, sizeof(MSG));
    if(fork() > 0){
        cout << "get in father" << endl;
        msg.mtype = 1;
        strcpy(msg.buf, "China");
        msgsnd(msgid, &msg, sizeof(MSG), 0);    //将数据放入消息队列中
        wait(NULL);
        msgctl(msgid, IPC_RMID, NULL);          //从系统中删除该消息队列以及仍在消息队列中的数据
        cout << "The after : " << msg.buf << endl;
        exit(0);
    }else{
        cout << "get in child " << endl;
        sleep(2);
        msgrcv(msgid, &msg, sizeof(MSG), 1, 0); //
        cout << msg.buf << endl;
        //puts(msg.buf);
        exit(0);
        
    }
    return 0;
}
