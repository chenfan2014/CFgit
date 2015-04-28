#include <iostream>
#include <string>
#include <vector>
#include <pwd.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
using namespace std;

static void myAlarm(int signo){
    struct passwd *rootPtr;
    
    cout << "In signal handler" << endl;

    if((rootPtr = getpwnam("root")) == NULL){
        cout << "getpwnam root" << endl;
    }
    alarm(1);
}

int main(int argc, const char *argv[])
{
    struct passwd *ptr;
    signal(SIGALRM, myAlarm);   
    alarm(1);
    for( ; ; ){
        if((ptr = getpwnam("sar")) == NULL){
            cout << "getpwnam sar " << endl;
        }

        if(strcmp(ptr -> pw_name, "sar") != 0){
            cout << "return value corrupted, pw_name : " << ptr -> pw_name << endl;
        }

    }
    return 0;
}
