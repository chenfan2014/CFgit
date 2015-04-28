#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int semid;

void init(){
    int ret;
    unsigned short sem_array[2];
    union semun{
        int val;
        struct semid_ds *buf;
        unsigned short *array
    }arg;

    semid  = semget((key_t)1234, 2, IPC_CREAT | 0644);
    sem_array[0] = 0;
    sem_array[1] = 10;
    arg.array = sem_array;
    ret = semctl(semid, 0, SETALL, arg);
    if(ret == -1){
        ERR_EXIT("semctl SETALL failed ");
    }
    cout << "Producer init success " << endl;
    cout << "Space init success" << endl;
}

void del(){
    semctl(semid, IPC_RMID, 0);
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
