#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    char host [] = "www.sina.com.cn";
    struct hostent *ht = NULL;
    
    char str[30] = " ";
    ht = gethostbyname(host);
    if(ht){
        int i = 0;
        cout << "Get the host " << ht << endl;
        cout << "Name : " << ht -> h_name << endl;

        cout << (ht -> h_addrtype == AF_INET ? "AF_INET": "AF_INET6") << endl;
        cout << "Length : " << ht -> h_length << endl;

        for(i = 0; ; i ++){
            if(ht -> h_addr_list[i] != NULL){
                cout << "IP : " << inet_ntop(ht -> h_addrtype, ht -> h_addr_list[i], str, 30) << endl;
            }else{
                break;
            }
        }

        for(i = 0; ; i ++){
            if(ht -> h_aliases[i] != NULL){
                cout << "Alias is  " << ht -> h_aliases  << endl;
            }else{
                break;
            }
        }
    }
    return 0;
}
