#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int child_events = 0;

void child_sig_handler(int x){
    child_events ++;
    signal(SIGCHLD, child_sig_handler);
}

int main(int argc, const char *argv[])
{
    sigset_t sigmask, orig_sigmask;
    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGCHLD);

    sigprocmask(SIG_BLOCK, &sigmask, &orig_sigmask);

    signal(SIGCHLD, child_sig_handler());

    for(;;){
        for(; child_events > 0; child_events --){
            
        }

        r = pselect(nfds, &rd, &wr, &er, 0, &orig_sigmask);
    }
    return 0;
}
