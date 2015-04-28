#include <limits.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>


//const int MAXSTRING = 4096;

pthread_mutex_t envMutex;

static pthread_once_t initDone = PTHREAD_ONCE_INIT;

//static char envbuf[MAXSTRING];

extern char **environ;

static void threadInit(void)
{
    pthread_mutexattr_t attr;
    
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&envMutex, &attr);
    pthread_mutexattr_destroy(&attr);
}

int getEnv(const char *name, char *buf, int bufLen)
{
    int i, len, olen;

    pthread_once(&initDone, threadInit);
    len = strlen(name);
    pthread_mutex_lock(&envMutex);
    for (i = 0; environ[i] != NULL; i++) {
        if((strncmp(name, environ[i], len) == 0) && environ[i][len] == '='){
                
            olen = strlen(&environ[i][len + 1]);
            if(olen >= bufLen){
                pthread_mutex_unlock(&envMutex);
                return ENOSPC;
            }
            strcpy(buf, &environ[i][len + 1]);
            pthread_mutex_unlock(&envMutex);
            return 0;
        }
    }
    pthread_mutex_unlock(&envMutex);
    return ENOENT;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
