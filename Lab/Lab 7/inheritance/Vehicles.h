#include<iostream>

using namespace std;

class Vehicles
{
protected:
    int reg_num;
    string color;

public:
    Vehicles() : reg_num(0), color("") {}

    Vehicles(int a, string b) : reg_num(a), color(b) {}

    void read()
    {
        cout << "Enter registration number: " << endl;
        cin >> reg_num;
        cout << "Enter color: " << endl;
        cin >> color;
    }

    void display()
    {
        cout << "Registration number: " << reg_num << endl;
        cout << "Color: " << color << endl;
    }

    int get_reg()
    {
        return reg_num;
    }

};
