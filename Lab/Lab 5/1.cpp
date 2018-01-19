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

    INTEGER operator ++()
    {
        int a = ++value;
        return INTEGER(a);
    }

    INTEGER operator ++(int)
    {
        int a= value++;
        return INTEGER(a);
    }

    INTEGER operator --()
    {
        int a= --value;
        return INTEGER(a);
    }

    INTEGER operator --(int)
    {
        int a = value--;
        return INTEGER(a);
    }

};


int main()
{
    INTEGER a(10), b(20);
    INTEGER c,e, d(100);

    c=(a/b) - (a+b) + (b*a);
    c.display();

    ++c;
    c.display();

    c++;
    c.display();

    --c;
    c.display();
    c--;
    c.display();

    if(c>=d)
    {
        cout<< "c is greater or equal to d" << endl;
    }
    else
        cout << "not greater or equal" << endl;


    return 0;
}
