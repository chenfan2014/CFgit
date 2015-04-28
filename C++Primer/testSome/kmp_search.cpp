int kmp_search(const char *src, int slen, const char patn, int ple, const int *nextval, int pos)
{
    int i = pos;
    int j = 0;

    while(i < slen & j < plen)
    {
        if(j == -1 || src[i] == patn[j]){
            ++i;
            ++j;
        }else{
            j = nextval[j];         //当匹配失败的时候直接用p[j_next]与s[i]中进行比较
        }
    }
    
    if(j >= plen){
        return i - plen;
    }else{
        return -1;
    }
}
void get_nextval(char const *ptrn, int plen, int *nextval)
{
    int i = 0, nextval[i] = -1;
    int j = -1;
    
    while(i < plen - 1){
        if(j == -1 || ptrn[i] == ptrn[j])
        {
            ++i;
            ++j;

            if(ptrn[i] != ptrn[j]){
                nextval [i] = j;
            }else{
                nextval[i] = nextval[j];
            }
        }
        else{
            j = nextval[j];
        }
    }
}
