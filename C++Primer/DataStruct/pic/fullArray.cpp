const int N = 13;       //n的最大值

int d[N];   //记录解
int v[N];   //记录某个值是否遍历过，遍历过是1，否则是0；
int n;

void DFS(int depth)
{
    if(depth >= n){                     //这个意思是我们遍历完了已经
        for(int i = 0; i != n; i ++){
            cout << d[i];
        }
        cout << endl;
        return ;
    }
    
    for(int i = 1; i != n; i ++){
        if(v[i] == 0){
            v[i] = 1;
            d[depth] = i;
            DFS(depth + 1); 
            v[i] = 0;
        }
    }
}

int main(int argc, const char *argv[])
{
    cin >> n;               //n就是我们排列数的个数
    memset(v, 0, n);        
    DFS(0);                 //从根节点开始遍历
    return 0;
}
