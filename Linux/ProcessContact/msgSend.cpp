#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

const int LEN = 127;

struct MSG{
    long mtype;
    char buffer[LEN + 1];
    string str;
};

int main(int argc, const char *argv[])
{
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1){
        ERR_EXIT("error msgget");
    }

    MSG msg;
    memset(&msg, 0, sizeof(msg));
    msg.mtype = 1;  //ｔｙｐｅ> 0返回队列中的消息类型为type的第一个消息
    strncpy(msg.buffer, "guangzhou", LEN);
    msgsnd(msgid, &msg, sizeof(msg), IPC_NOWAIT);

    memset(&msg, 0, sizeof(msg));
    msgrcv(msgid, &msg, sizeof(msg), 2, 0);
    cout << "recv from : " << msg.buffer << endl;
    return 0;
}
