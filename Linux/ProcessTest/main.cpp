#include "header.h"
#include <time.h>

using namespace std;

int main(int argc, const char *argv[])
{
    pid_t pid;
    //bufferSize = 0;                 //开始的时候是没有东西的
    while(1){
        if((pid = fork()) < 0){
            cerr << "Wrong fork" << endl;
        }else if(pid == 0){        //子进程
            if(Buffer > 0 && Buffer < 5){
                consumer();
                sleep(1);
                cout << "Consumer " << endl;
            }
            //消费
        }else{
            //生产
            if(Buffer < 5 && Buffer >= 0){
                producer();
                sleep(1);
                cout << "Producer" << endl;
            }
        }
    }
    return 0;
}
