#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    char name[1024], line[128];
    memset(name, 0, 1024);
    memset(line, 0, 128);
    FILE *fp;
    printf("%s\n", tmpnam(NULL));
    tmpnam(name);
    printf("%s\n", name);

    if((fp = tmpfile()) == NULL){
        cout << "err temfile" << endl;
    }
    fputs("one line of output : \n", fp);

    rewind(fp);
    if(fgets(line, sizeof(line), fp) == NULL){
        cout << "err fgets" << endl;
    }
    fputs(line, stdout);
    return 0;
}
