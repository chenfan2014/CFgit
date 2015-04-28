#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

struct shmid_ds{
    struct ipc_perm shm_perm;
    size_t shm_segsz;
    time_t shm_atime;
    time_t shm_dtime;
    time_t shm_ctime;
    pid_t shm_cpid;
    pid_t shm_lpid;
    shmatt_t shm_nattch;
};
static char msg[] = "South China Normal Unversity";

int main(int argc, const char *argv[])
{
    key_t key;
    int semId, shmId;
    char i, *shms, *shmc;
    struct semid_ds buf;
    int value = 0;
    char buffer[80];
    memset(buffer, 0, 80);
    pid_t pid;

    key = ftok("/ipc.sem", 'a');
    shmId = shmget(key, 1024, IPC_CREAT | 0604);

    semId = CreateSem(key, 0);

    if((pid = fork()) < 0){
        ERR_EXIT("error fork");
    }else if(pid == 0){
        shmc = (char *) shmat (shmid, 0, 0);
        Sem_V(semId);
        cout << "The value of Share value is : " << shmc << endl;
        shmdt(shmc);
    }else{
        shms = (char *)shmat(shmId, 0, 0);
        memcpy(shms, msg, strlen(msg) + 1);
        sleep(10);
        Sem_P(semId);
        shmdt(shms);
        DestroySem(semId);
    }
    return 0;
}
