#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    FILE *fp = fopen("readfile.cpp", "rb");
    char buf[1024];
    memset(buf, 0, 1024);
    fread(buf, sizeof(char), 1024, fp);
    cout << buf << endl;
    fclose(fp);

    FILE *fp2 = fopen("test.txt", "a+");
    while(cin >> buf){
        fwrite(buf, sizeof(char), strlen(buf), fp2);
        fwrite("\n", sizeof(char), 2, fp2);
    }
    fclose(fp2);
    return 0;
}
