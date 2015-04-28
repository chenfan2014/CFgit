#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

struct Msg{
    long mType;
    char buf[64];
};

int main(int argc, const char *argv[])
{
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1){
        ERR_EXIT("error msgget");
    }

    Msg  msg;
    memset(&msg, 0, sizeof(msg));
    if(fork() > 0){
        msg.mType = 1;  //返回同类型第一个
        strcpy(msg.buf, "write");
        msgsnd(msgid, &msg, sizeof(msg), 0);
        cout << "Send content : " << msg.buf  << endl;
        wait(NULL);
        msgctl(msgid, IPC_RMID, NULL);
        exit(0);
    }else{
        sleep(2);
        memset(msg.buf, 0, 64);
        cout << "First init : " << msg.buf << endl;
        msgrcv(msgid, &msg, sizeof(msg), 1, 0);
        cout << "Recv content : " << msg.buf << endl;
        exit(0);
    }

    return 0;
}
