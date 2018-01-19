#include<iostream>
#include<cmath>

using namespace std;

struct point
{
    int x_axis;
    int y_axis;
};

double cal_dis(int a, int b)
{
    double d, p;
    d=(a*a)+(b*b);
    p=sqrt(d);
    return p;
}

int main()
{
    struct point P;
    int i;
    double dist[2];

    for(i=0; i<2; i++)
    {
        cout << "Enter coordinates for p1: ";
        cin >> P.x_axis >> P.y_axis;
        dist[i]=cal_dis(P.x_axis, P.y_axis);
    }

    for(i=0; i<2; i++)
    {
        cout << "Euclidean distance from center to p" <<i+1 << ": " << dist[i] << endl;
    }

    return 0;
}
