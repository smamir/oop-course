#include<iostream>

using namespace std;

class Cargo : public Vehicles
{
private:
    int l_capacity;
    string cv_type;

public:
    Cargo(): Vehicles(), l_capacity(0), cv_type("") {}
    Cargo(int c, string d, int a, string b): Vehicles(c,d), l_capacity(a), cv_type(b) {}
    Cargo(int a) : l_capacity(a) {}

    void read()
    {
        Vehicles::read();
        cout << "Enter load capacity: " << endl;
        cin >> l_capacity;
        cout << "Enter vehicle type: " << endl;
        cin >> cv_type;
    }

    void display()
    {
        Vehicles::display();
        cout << "Seating capacity: " << l_capacity << endl;
        cout << "Vehicle type: " << cv_type << endl;
    }

    int get_capacity()
    {
        return l_capacity;
    }

    Cargo operator +(Cargo x)
    {
        return Cargo(l_capacity+x.l_capacity);
    }

    Cargo operator -(Cargo x)
    {
        return Cargo(l_capacity-x.l_capacity);;
    }

};
