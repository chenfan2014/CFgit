#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
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
        ERR_EXIT("err ftok");
    }

    int shmid = shmget(key, 4096, IPC_CREAT);
    if(shmid == -1){
        ERR_EXIT("error shmget");
    }

    char *pMap = (char *) shmat (shmid, NULL, 0);
    cout << "Read from server : " << pMap << endl;
    if(shmctl(shmid, IPC_RMID, 0) == -1){
        ERR_EXIT("err shmctl");
    }
    return 0;
}
