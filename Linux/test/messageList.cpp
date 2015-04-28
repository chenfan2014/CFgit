#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <time.h>
#include <sys/ipc.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
void messageShowAttr(int msgId, struct msqid_ds msgInfo){
    int ret = -1;
    sleep(1);
    
    if((ret = msgctl(msgId, IPC_STAT, &msgInfo)) == -1){
        ERR_EXIT("Error to get message ");
    }

    cout << endl;
    cout << "The byte now in list is : " << msgInfo.msg_cbytes << endl;
    cout << "List message count : " << msgInfo.msg_qnum << endl;
    cout << "Max bytes in List is : " << msgInfo.msg_qbytes << endl;
}
int main(int argc, const char *argv[])
{
    int ret = -1;
    int msgFlags, msgId;
    key_t key;

    struct msgmbuf{
        int mtype;
        char mtext[10];
    };

    struct msgid_ds msgInfo;
    struct msgmbuf msgMBuf;

    int msgSFlags, 
    return 0;
}
