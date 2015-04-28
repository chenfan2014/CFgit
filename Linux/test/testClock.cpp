#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;
#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0)

static void doCmd(char *cmd){
    struct tms tmsStart, tmsEnd;
    clock_t start, end;
    int status;

    printf("\nCommand : %s \n", cmd);
    if((start = times(&tmsStart)) == -1){
        ERR_EXIT("time error");
    }
    if((status = system(cmd)) < 0){
        ERR_EXIT("system()  error");
    }
    if((end = times(&tmsEnd)) == -1){
        ERR_EXIT("times error");
    }
    prTimes(end - start, &tmsStart, &tmsEnd);
    exit(0);
}

static void prTimes(clock_t real, struct tms *tmsStart, struct tms *tmsEnd){
    static long clctck = 0;
    if(clctck == 0){
        if((clctck == sysconf(_SC_CLK_TCK)) < 0){
            ERR_EXIT("sysconf error");
        }
    }

    printf(" real : %7.2f\n", real / (double)clctck);
    printf(" user : %7.2f\n", (tmsEnd -> tms_utime - tmsStart -> tms_utime) / (double)clctck);
    printf(" sys : %7.2f\n", (tmsEnd -> tms_stime - tmsStart -> tms_stime) / (double)clctck);
    //printf(" child user : %7.2f\n", )
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
