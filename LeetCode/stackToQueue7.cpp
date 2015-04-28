#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Queue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int x)
        {
            s1.push();
        }
        int pop(){

            if(s1.empty() && s2.empty()){
                return -1;
            }

            if(!s1.empty)
            

            int i = top();
            s2.pop();
            return i;
        }
        int top(){
            if(s2.empty()){
                while(s1.top()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }
};

int main(int argc, const char *argv[])
{
    Queue qu;
    int n;
    cin >> n;
    int count = 0;
    while(count != n)
    {
        string s;
        int i;
        cin >> s >> i;
        //getline(cin, s);
    
        if(s == "push"){
            qu.push(1);
        }
        if(s == "pop"){
            qu.pop();
        }
        count ++;
    }
    cout << qu.top() << endl;
    return 0;
}
