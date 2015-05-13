#include <iostream>
#include <string>
#include <vector>


template<typename T>
class Point3D{
    private:
        T x_;
        T y_;
        T z_;
    public:
        Point3D(T x, T y, T z)
            :x_(x), y_(y), z_(z)
        {}

        T x(){
            return x_;
        }
        T y(){
            return y_;
        }
        T z(){
            return z_;
        }
};

template<typename T>
inline ostrean &operator << (ostrean &os, const Point3D<T> &pt)
{
    os << pt.x() << " " << pt.y() << " " << pt.z() << endl;
}

class Point{
    
}
