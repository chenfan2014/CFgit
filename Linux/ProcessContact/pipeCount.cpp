#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(int argc, const char *argv[])
{
    char buf[] = {"aaa bbb ccc ddd eee fff ggg"};
    FILE *fp = popen("wc -w", "w");
    fwrite(buf, sizeof(buf), 1, fp);
    pclose(fp);
    return 0;
}
