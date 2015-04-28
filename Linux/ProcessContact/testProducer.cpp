#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
void init();    //initlization semaphore
void del(); //delete semaphore
int sem_id;
int main(int argc, char *argv[])
{
    struct sembuf sops[2];
    /*set operate way for semaphore*/
    sops[0].sem_num = 0;    //第一个信号的编号，表示生产了几个产品
    sops[0].sem_op = 1; //进行V操作
    sops[0].sem_flg = 0;    //或写为SEM_UNDO
    sops[1].sem_num = 1;    //第二个信号编号，表示还可以生产几个产品
    sops[1].sem_op = -1;    //进行P操作
    sops[1].sem_flg = 0;    //或写为SEM_UNDO
    init(); //初始化操作
    printf("this is a producor\n");
    while(1)
    {
        printf("\n\nbefore produce\n");
        printf("productor number is %d\n", semctl(sem_id, 0, GETVAL));
        printf("space number is %d\n", semctl(sem_id, 1, GETVAL));
        semop(sem_id, (struct sembuf*)&sops[1], 1);
        printf("now producing .....\n");
        semop(sem_id, (struct sembuf*)&sops[0], 1);
        printf("space number is %d\n", semctl(sem_id, 1, GETVAL));
        printf("productor number is %d\n", semctl(sem_id, 0, GETVAL));
        sleep(2);
    }
    del();
}
void init()
{
    int ret;
    unsigned short sem_array[2];
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    }arg;
    sem_id = semget((key_t)1234, 2, IPC_CREAT|0644);/*get semaphore include two sem*/
    
    /*set sem's vaule*/
    sem_array[0] = 0;
    sem_array[1] = 10;
    arg.array = sem_array;
    ret = semctl(sem_id, 0, SETALL, arg);   //将所有semun.array的值设定到信号集中，第二个参数为0
    if(ret == -1)
    {
        printf("SETALL failed (%d)\n", errno);
    }
    printf("productor init is %d\n", semctl(sem_id, 0, GETVAL));
    printf("space init is %d\n\n", semctl(sem_id, 1, GETVAL));
}
void del()
{
    semctl(sem_id, IPC_RMID, 0);    //删除信号集
}
