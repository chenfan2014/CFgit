#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int fread = open("test.txt", O_APPEND);
    char rbuf[1024] = "";
    char wbuf[] = "Love China";
    write(fread, wbuf, strlen(wbuf));
    lseek(fread, 10, SEEK_CUR);
    read(fread, rbuf, 10);
    cout << rbuf << endl;
    return 0;
}
