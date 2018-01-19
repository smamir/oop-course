#include<iostream>
#include<iomanip>

using namespace std;

class Weight
{
private:
    double pounds;
    double ounces;

public:
    void setPounds(double p)
    {
        pounds=p;
    }
    void setOunces(double o)
    {
        ounces=o;
    }
    double getPounds()
    {
        return pounds;
    }
    double getOunces()
    {
        return ounces;
    }
    double toPounds()
    {
        double temp;
        temp=pounds+(ounces/16);
        return temp;
    }
    double toOunces()
    {
        double temp;
        temp=ounces+(pounds*16);
        return temp;
    }
};

int main()
{
    class Weight a,b;
    double p,o;
    cout << "Enter weight of first product: ";
    cin >> p >> o;
    a.setPounds(p);
    a.setOunces(o);
    cout << "Enter weight of second product: ";
    cin >> p >> o;
    b.setPounds(p);
    b.setOunces(o);

    cout.setf(ios::fixed);
    cout << "\nAfter converting 1st product into pounds: "<< setw(8)
    <<setprecision(2) << a.toPounds() << " pounds" << endl;
    cout << "After converting 2nd product into pounds: " << setw(8)
    << setprecision(2) << b.toPounds() << " pounds" << endl;
    cout << "After converting 1st product into ounces: " << setw(8)
    << setprecision(2) << a.toOunces() << " ounces" << endl;
    cout << "After converting 2nd product into ounces: " << setw(8)
    << setprecision(2) << b.toOunces() << " ounces" << endl;

    return 0;
}
