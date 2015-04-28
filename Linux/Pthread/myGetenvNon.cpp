#include <limits.h>
#include <string.h>

const int MAXSTRING = 4096;

static char envbuf[MAXSTRING];

extern char **environ;

char *getenv(const char *name)
{
    int i;
    int len = strlen(name);
    for(i = 0; environ[i] != NULL; i ++){
        if((strncmp(name, environ[i], len) == 0) && (environ[i][len] == '=')){
            strncpy(envbuf, &environ[i][len + 1], MAXSTRING - 1);
            return envbuf;
        }
    }
    return NULL;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
