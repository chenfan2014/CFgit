#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
using namespace std;


#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE);\
    }while(0)

#define PERM S_IRUSR | S_IWUSR  //表示用户可读可写0666

int main(int argc, const char *argv[])
{
    int shmid = shmget(IPC_PRIVATE, 1024, PERM);
    // int shmge(key_t key, size_t size, int flag);
    if(shmid == -1){
        ERR_EXIT("shgget");
    }

    if(fork() > 0){
        char *pAddr = (char *)shmat(shmid, NULL, 0);
        //shmat连接到我们创建的共享存储段地址空间,获取首地址

        memset(pAddr, '\0', 1024);
        strncpy(pAddr, "share memory", 1024);//写入东西
        cout << "Parent write content : " << pAddr << endl;
        sleep(2);
        wait(NULL); //防止僵尸进程
        shmctl(shmid, IPC_RMID, 0); //删除共享内存
        exit(0);
    }else{
        sleep(5);   //让父进程有足够时间写
        char *cAddr = (char *) shmat (shmid, NULL, 0);   
        cout << "Child read content : " << cAddr << endl;
        exit(0);
    }

    return 0;
}
