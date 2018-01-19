#include<iostream>

using namespace std;

class INTEGER
{
private:
    int value;

public:
    INTEGER(): value(0) {}

    INTEGER(int x): value(x) {}

    void display()
    {
        cout << value << endl;
    }

    INTEGER operator+ (INTEGER p)
    {
        int a=value+p.value;
        return INTEGER(a);
    }

    INTEGER operator- (INTEGER p)
    {
        int a=value-p.value;
        return INTEGER(a);
    }

    INTEGER operator* (INTEGER p)
    {
        int a = value*p.value;
        return INTEGER(a);
    }

    INTEGER operator/ (INTEGER p)
    {
        int a = value/p.value;
        return INTEGER(a);
    }

    INTEGER operator% (INTEGER p)
    {
        int a=value%p.value;
        return INTEGER(a);
    }

    void operator +=(INTEGER p)
    {
        value = value + p.value;
    }

    void operator -=(INTEGER p)
    {
        value = value -p.value;
    }

    void operator *=(INTEGER p)
    {
        value = value*p.value;
    }

    void operator /=(INTEGER p)
    {
        value = value/p.value;
    }

    bool operator >(INTEGER p)
    {
        if(value>p.value)
            return true;
        else
            return false;
    }

    bool operator <(INTEGER p)
    {
        if(value<p.value)
            return true;
        else
            return false;
    }

    bool operator >=(INTEGER p)
    {
        if(value>=p.value)
            return true;
        else
            return false;
    }

    bool operator <=(INTEGER p)
    {
        if(value<=p.value)
            return true;
        else
            return false;
    }

    bool operator ==(INTEGER p)
    {
        if(value==p.value)
            return true;
        else
            return false;
    }

    bool operator !=(INTEGER p)
    {
        if(value!=p.value)
            return true;
        else
            return false;
    }

    void operator ++()
    {
        value = value + 1;
    }

    void operator ++(int)
    {
        value = value +1;
    }

    void operator --()
    {
        --value;
    }

    void operator --(int)
    {
        value--;
    }

};

class point
{
public:
    INTEGER x;
    INTEGER y;

private:
    point():x(0),y(0) {}
    point(INTEGER a, INTEGER b): x(a), y(b) {}



};


int main()
{
    INTEGER a(5), b(10);
    INTEGER c, d(100);



    return 0;
}
