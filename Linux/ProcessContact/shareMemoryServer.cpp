#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
using namespace std;


#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    key_t key = ftok("b.dat", 1);
    if(key == -1){
        ERR_EXIT("error ftok");
    }
    
    int shmid = shmget(key, 4096, IPC_CREAT);//创建共享内存段
    if(shmid == -1){
        ERR_EXIT("shmget error");
    }
    
    char *pMap = (char *) shmat (shmid, NULL, 0);
    memset(pMap, '\0', 4096);
    cout << "success" << endl;
    strncpy(pMap, "Test server ", 4096);
    if(shmdt(pMap) == -1){
        ERR_EXIT("shmdt error");
    }
    return 0;
}
