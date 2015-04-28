#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Point{
    public:
        Point(int x, int y)
            :lhs(x),
            rhs(y)
        {}

        void setLval(int x){
            lhs = x;
        }

        void setRval(int y){
            rhs = y;
        }
    private:
        int lhs;
        int rhs;
};

struct RectData{
    Point ulhc;
    Point lrhc;
};

class Rect{
    public:
        Point & upperLeft() const{
            return pData -> ulhc;
        }

        Point & upperRight() const{
            return pData -> lrhc;
        }

        Point print() const{
            cout << pData.ulhc << " " << pData.lrhc << endl;
        }
    private:
        trl::shared_ptr<RectData> pData;
};

int main(int argc, const char *argv[])
{
    Point pointOne(0, 0);
    Point pointTwo(100, 100);

    const Rect rec(pointOne, pointTwo);
    
    rec.print();
    
    return 0;
}
