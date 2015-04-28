#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    FILE *fp = fopen("test.txt","rb");
    int c;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }
    fclose(fp);

    /*
    while((c = getchar()) != EOF){
        printf("%c", c);
    }
    */
    while((c = getc(stdin)) != EOF){
        putc(c, stdout);
    }

    return 0;
}
