#include<iostream>
#include "INTEGER.h"

using namespace std;

class Point
{
private:
    INTEGER x;
    INTEGER y;

public:
    Point(INTEGER a, INTEGER b): x(a), y(b) {

    }
    Point(): x(0), y(0) {

    }

    Point operator +(Point p)
    {
        INTEGER X = x + p.x;
        INTEGER Y = y + p.y;
        return Point(X,Y);
    }

    void display()
    {
        cout << "X is: " << x.display() << endl;
        cout << "Y is: " >> y.display() << endl;
    }

};
