#include<iostream>

using namespace std;

class Passenger : public Vehicles
{
private:
    int s_capacity;
    string v_type;

public:
    Passenger(): Vehicles(), s_capacity(0), v_type("") {}
    Passenger(int c, string d, int a, string b): Vehicles(c,d), s_capacity(a), v_type(b) {}
    Passenger(int a) : s_capacity(a) {}

    void read()
    {
        Vehicles::read();
        cout << "Enter seating capacity: " << endl;
        cin >> s_capacity;
        cout << "Enter vehicle type: " << endl;
        cin >> v_type;
    }

    void display()
    {
        Vehicles::display();
        cout << "Seating capacity: " << s_capacity << endl;
        cout << "Vehicle type: " << v_type << endl;
    }

    int get_capacity()
    {
        return s_capacity;
    }

    Passenger operator +(Passenger x)
    {
        return Passenger(s_capacity= s_capacity + x.s_capacity);
    }

    Passenger operator -(Passenger x)
    {
        return Passenger(s_capacity= s_capacity - x.s_capacity);
    }
};
