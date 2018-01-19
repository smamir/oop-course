#include<iostream>

using namespace std;

class Street
{
private:
    int miles;
    double yards;
    static int count;

public:
    Street(): miles(0), yards(0)
    {
        count++;
    }

    Street(int a, double b): miles(a), yards(b)
    {
        count++;
    }

    static int getCount()
    {
        return count;
    }


};

int Street::count=0;

int main()
{
    Street s1, s2;
    Street s3(10,100.4), s4(23, 450.3);

    return 0;
}
