#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
class meetTime{
    private:
        int begin_;
        int end_;
    public:
        meetTime(int begin, int end)
            :begin_(begin), end_(end)
        {}

        meetTime()
            :begin_(0), end_(0)
        {}

        void getValue(int begin, int end)
        {
            begin_ = begin;
            end_ = end;
        }
        void print() const{
            cout << begin_ << " " << end_ << endl;
        }

        int getBegin() const{
            return begin_;
        }
        int getEnd() const{
            return end_;
        }
};
int main(int argc, const char *argv[])
{
    meetTime mt;
    vector<meetTime> time;
    int meetNum;
    cout << "Please input the people to meeting : ";
    cin >> meetNum;
    int begin;
    int end;
    int count = 0;
    int flag = 0;
    while(count ++ != meetNum){
        cin >> begin >> end;
        vector<meetTime>::iterator it = time.begin();
        mt.getValue(begin, end);
        if(time.size() == 0){
            time.push_back(mt);
        }else{
            for(vector<meetTime>::size_type ix = 0; ix != time.size(); ++ix){
                if(begin < time[ix].getBegin()){
                    cout << "bigger" << endl;
                    time.insert(it + ix, mt);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                time.push_back(mt);
                flag = 0;
            }else{
                flag = 0;
            }
        }
    }
    for(vector<meetTime>::size_type ix = 0; ix != time.size(); ++ix){
        time[ix].print();
    }
    int place = 0;
    set<int> sEnd;
    for(vector<meetTime>::size_type ix = 0; ix != time.size(); ++ix){
        //这里是我们对所有的进行一次遍历
        if(sEnd.size() == 0){
            place ++;
            sEnd.insert(time[ix].getEnd());
        }else{
            for(set<int>::iterator it = sEnd.begin(); it != sEnd.end(); ++it){
                if(time[ix].getBegin() < *it){
                    sEnd.erase(it);
                    sEnd.insert(time[ix].getEnd());
                    break;
                }else{
                    place ++;
                    sEnd.insert(time[ix].getEnd());
                }
            }
        }
        
    }
    cout << "Place Need : " << place << endl;
    return 0;
}
