#include "apue.h"
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void prExit(int status){
    if(WIFEXITED(status)){
       cout << "Normal tremination, exit status is : " << WEXITSTATUS(status) << endl;
    }else if(WIFSIGNALED(status)){
        cout << "Abord tremination, exit status is : " << WEXITSTATUS(status) << endl;
    }
}
