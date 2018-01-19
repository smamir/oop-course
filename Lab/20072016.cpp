#include<bits/stdc++.h>
using namespace std;

class Distance_Others{
private:
    int meters;
    double cms;
public:
    Distance_Others(int a, double b):meters(a),cms(b){}
    Distance_Others():meters(0),cms(0.0){}
    void display(){
        cout << meters << " meters " << cms << " cms" << endl;
    }

};

class Distance_US{
private:
    int feet;
    double inches;
public:
    Distance_US(int a, double b):feet(a),inches(b){}
    Distance_US():feet(0),inches(0.00){}
    void display(){
        cout << feet << " feet " << inches << " inches" << endl;
    }
    ///conversion operator (user-defined to basic)
    operator double(){
        double fracFeet = feet + (inches/12);
        double m = fracFeet/3.28;
        return m;
    }
    ///conversion constructor (basic to user-defined)
    Distance_US(double t){
        double temp = t * 3.28;
        feet = static_cast<int>(temp);
        inches = (temp - feet) * 12;
    }
    ///conversion operator (Distance_US to Distance_Others)
    operator Distance_Others(){
        double fracFeet = feet + (inches/12);
        double m = fracFeet/3.28;
        //Distance_Others temp;
        //temp.setMeters(m);
        //temp.setCms((m-int(m))*100);
        double cm = ((m-int(m))*100);
        return Distance_Others (m,cm);
    }
};


int main(){
    Distance_US d1(5,4.9);
    d1.display();
    double m = d1;
    cout << "Equiv. meters: " << m << endl;
    Distance_US d2 = m;
    d2.display();
    Distance_Others d3 = d2;
    d3.display();
    return 0;
}
