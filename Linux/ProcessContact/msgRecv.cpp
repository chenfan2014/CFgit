#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <unistd.h>

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
};

int main(int argc, const char *argv[])
{
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1){
        ERR_EXIT("msgget error");
    }

    MSG msg;
    memset(&msg, 0, sizeof(msg));
    while(1){
        msgrcv(msgid, &msg, sizeof(msg), 1, 0);
        cout << "recv msg " << msg.buffer << endl;

        msg.mtype = 2;
        strncpy(msg.buffer, "shenzhen", LEN);
        msgsnd(msgid, &msg, sizeof(msg), 0);
    }
    return 0;
}
