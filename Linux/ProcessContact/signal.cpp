#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

union semun{        //必须重写这个共用体
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main(int argc, const char *argv[])
{
    int semid = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT)  ;    // 创建信号量集
    if(semid == -1){
        ERR_EXIT("error semget");
    }

    if(fork() == 0){
        struct sembuf sem;
        memset(&sem, 0, sizeof(sem));
        sem.sem_num = 0;
        sem.sem_op = 1;     //表示生产
        sem.sem_flg = 0;        
        union semun arg;
        arg.val = 0;
        semctl(semid, 0, SETALL, arg);

        while(1){
            semop(semid, &sem, 1);
            cout << "produce : " << sem.sem_num << endl;
            sleep(1);
        }
    }else{
        sleep(2);
        struct sembuf sem;
        memset(&sem, 0, sizeof(sem));
        sem.sem_num = 0;
        sem.sem_op = -1;
        sem.sem_flg = 0;
        while(1){
            semop(semid, &sem, 1);
            cout << "consumer : " << sem.sem_num << endl;
            sleep(2);
        }
    }
    return 0;
}
