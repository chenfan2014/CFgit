#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int TOKADD = 5;
const int MAXLINE = 1024;

void doLine(char *);
void cmdAdd(void);
int getToken(void);

int main(int argc, const char *argv[])
{
    char line[MAXLINE];
    memset(line, 0, MAXLINE);

    while(fgets(line, MAXLINE, stdin) != NULL){
        doLine(line);
    }
    return 0;
}

char *tokPtr;
void doLine(char *ptr){
    int cmd;
    tokPtr = ptr;
    while((cmd = getToken()) > 0)
    {
        switch(cmd)
        {
            case TOKADD:
                cmdAdd();
                break;
        }
    }
}

void cmdAdd(void)
{
    int token;
    token  = getToken();
}


int getToken(void)
{
    
}

