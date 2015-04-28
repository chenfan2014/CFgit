#ifndef __SOCKET_C__
#define __SOCKET_C__ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void signalHandler(void);
int socketInit(int , const char *);       //socket bind listen accept recv send 
int serverListenAccept(int );           //socket connect send recv
void serverMessage(int , int);
int  clientConnect(int, const char *);
void clientMessage(int );


#endif  /*__SOCKET_C__*/
