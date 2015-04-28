#include <signal.h>
typedef void (*sighandler_t)(int);
sighandler_t signal(int sigNum, sighandler_t handler);
void sig_pipe(int signo){
    cout << "Catch a SIGPIPE signal" << endl;
}
void sig_int(int signo){
    cout << "Catch a SIGINT signal" << endl;
}
signal(SIGINT, sig_pipe);
