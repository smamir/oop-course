#include <iostream>
#include "Vehicles.h"
#include "Passenger.h"
#include "Cargo.h"

using namespace std;

void max_p(Passenger p[])
{
    int max=0;
    int reg=0;
    for(int i=0; i<3; i++)
    {
        if(p[i].get_capacity()>max)
        {
            max=p[i].get_capacity();
            reg=p[i].get_reg();
        }
        else
        {
            max=max;
        }
    }
    cout << "Maximum seating capacity: " << max << " " << "Registration number is: " << reg << endl;
}

void max_l(Cargo c[])
{
    int max=0;
    int reg=0;
    for(int i=0; i<2; i++)
    {
        if(c[i].get_capacity()>max)
        {
            max=c[i].get_capacity();
            reg=c[i].get_reg();
        }
        else
        {
            max=max;
        }
    }
    cout << "Maximum load capacity: " << max << " " << "Registration number is: " << reg << endl;
}

int main()
{
    Passenger p[3];
    Cargo c[2];
/*
    for(int i=0; i<3; i++)
    {
        p[i].read();
    }

    for(int i=0; i<3; i++)
    {
        p[i].display();
    }
    max_p(p);

    for(int i=0; i<2; i++)
    {
        c[i].read();
    }

    for(int i=0; i<2; i++)
    {
        c[i].display();
    }

    max_l(c);

    */
    Cargo c1(101, "green", 30, "bus"), c2(103, "red", 40, "bus"), c3;
    c3 = c1 + c2;

    c3.display();
    return 0;
}
