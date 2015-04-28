#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#define IPADDRESS "127.0.0.1"
#define PORT 8989
#define MAXLINE 1024
#define LISTENSIZE 5

using namespace std;

#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0)

int main(int argc, const char *argv[])
{
    struct  sockaddr_in serverAddr;
    int serverfd, clientfd;
    socklen_t serverAddrLen;
    int ret;
    char buffer[1024] = " ";

    fd_set rset, allset;            //文教描述符集
    int maxfd, maxi;
    int clientfds[FD_SETSIZE];      //保存客户端连接描述符
    int nready;
    
    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("error socket");
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    //bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;        //复制协议族
    serverAddr.sin_port = htons(PORT);      //转变成网络字节序
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS); 
    
    if((ret = bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr))) == -1){
        ERR_EXIT("bind error");
    }
    
    if(listen(serverfd, LISTENSIZE) == -1){
        ERR_EXIT("listen error");
    }
    
    FD_ZERO(&allset);                   //清理文件描述符集合
    FD_SET(serverfd, &allset);          //把serverfd描述符加入到allset描述符集合中
    maxfd = serverfd;

    for(;;){
        rset = allset;      
        
        nready = select(maxfd + 1, &rset, NULL, NULL, NULL);    //获取可用文件描述符个数
        if(nready == -1){
            ERR_EXIT("select error");
        }

        if(FD_ISSET(serverfd, &rset)){      //测试serverfd描述符是否准备好
            serverAddrLen = sizeof(serverAddr);

            if((clientfd = accept(serverfd, (struct sockaddr *)&serverAddr, &serverAddrLen)) == -1){
                if(errno == EINTR){
                    continue;
                }else{
                    ERR_EXIT("error accept");
                }
            }

            //连接成功
            cout << "Accept a new Client : " << inet_ntoa(serverAddr.sin_addr) << " And the PORT is : "<< serverAddr.sin_port << endl;

            //将新的连接描述符放入到数组中
            int i;
            for(i = 0; i != FD_SETSIZE; i ++){
                if(clientfds[i] < 0){
                    clientfds[i] = clientfd;
                    break;
                }
            }

            if(i == FD_SETSIZE){
                cout << "Too many clients here" << endl;
            }

            FD_SET(clientfd, &allset);    //把新的文件描述符加入到集合中

            maxfd = (clientfd > maxfd ? clientfd : maxfd);  //描述符个数
            maxi = (i > maxi ? i : maxi);      // 记录客户连接套接字个数
            
            if(-- nready <= 0){
                continue;
            }

            int j, n;
            for(j = 0; j != maxi; j ++){
                if(clientfds[j] < 0){
                    continue;
                }

                if(FD_ISSET(clientfds[j], &rset)){
                    n = read(clientfds[j], buffer, MAXLINE);

                    if(n == 0){
                        close(clientfds[j]);
                        FD_CLR(clientfds[j], &allset);
                        clientfds[j] = -1;
                        continue;
                    }
                    cout << "Read msg is : " << buffer << endl;
                    write(clientfds[j], buffer, n);
                }

            }
        }
    }

    return 0;
}
