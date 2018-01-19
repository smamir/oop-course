#include<iostream>
#include<cmath>

using namespace std;

class Point
{
private:
    int x_axis;
    int y_axis;
    double dist;

public:
    void setValue(int x, int y)
    {
        x_axis=x;
        y_axis=y;
    }
    void calculateDistance()
    {
        dist = sqrt((x_axis*x_axis)+(y_axis*y_axis));
    }
    double getValue()
    {
        calculateDistance();
        return dist;
    }
};

int main()
{
    class Point p1,p2;
    int a, b, i;
    double d1, d2;

    cout << "Enter coordinates for p1: ";
    cin >> a >> b;
    p1.setValue(a,b);
    d1 = p1.getValue();

    cout << "Enter coordinates for p2: ";
    cin >> a >> b;
    p2.setValue(a,b);
    d2 = p2.getValue();

    cout << "Euclidean distance from center to p1: " << d1 << endl;
    cout << "Euclidean distance from center to p2: " << d2 << endl;

    return 0;
}
