#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

int main(int argc, const char *argv[])
{
    string ip = "192.168.1.1";
    struct in_addr myAddr;
    struct in_addr myAddr2;

    int iret = inet_aton(ip.c_str(), &myAddr);  //ip转为32位地址
    if(iret == 0){
        cout << "wrong inet_aton" << endl;
        exit(1);
    }
    cout << myAddr.s_addr << endl;
    


    int iaddr = inet_pton(AF_INET, ip.c_str(), &myAddr2);
    cout << myAddr2.s_addr << endl;

    cout << inet_addr(ip.c_str()) << endl;

    char *buf = inet_ntoa(myAddr);              //32位网络地址转化成ip地址
    cout << buf << endl;
    
    char *buf2;
    inet_ntop(AF_INET, &myAddr2, buf2, 32);
    cout << buf2 << endl;
    

    return 0;
}
