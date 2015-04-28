#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test{
    public:
        Test(){
            for(int i = 0; i != Num; i ++){
                scores_[i] = 0;
            }
        }

        Test(const Test &arr){
            for (int i = 0; i != Num; i++) {
                scores_[i] = arr.scores_[i];
            }
        }
        

        ~Test()
        {};
        
        
        void valueTest(int value, int local){
            scores_[local] = value;
        }



        void print() const{
            for (int i = 0; i < Num; i++) {
                cout << scores_[i] << " ";
            }
            cout << endl;
        }


    private:
        static const int Num = 5;
        int scores_[Num];
        int value_;
};

int main(int argc, const char *argv[])
{
    Test T;
    int value;
    for(int i = 0; i != 5; i ++){
        value = i + 1;
        T.valueTest(value, i);
    }
    T.print();


    Test T2(T);
    T2.print();

    return 0;
}
