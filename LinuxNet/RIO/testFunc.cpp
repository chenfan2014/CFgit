void process_conn_server(int sockfd){
    ssize_t size = 0;
    char buffer[1024];
    for(;;){
        size = recv(sockfd, buffer, 1024, 0);
        if(size == 0){
            return 
        }

        sprintf(buffer, "%d bytes altogeter\n", size);
        send(s, buffer, strlen(buffer) + 1, 0);
    }
}

void process_conn_client(int sockfd){
    ssize_t size = 0;
    char buffer[1024];

    for(;;){
        size = read(0, buffer, 1024);
        if(size > 0){
            send(sockfd, buffer, size, 0);
            size = recv(s, buffer, 1024, 0);
            write(1, buffer, size);
        }
    }
}
void sig_process(int signo){
    cout << "Catch a exit signal" << endl;
    _exit(0);
}
void sig_pipe(int signo){
    coout << "Catch a sigpipe signal" << endl;
}
