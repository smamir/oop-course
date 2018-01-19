#include <iostream>
#include<cmath>

#define SIZE 10

using namespace std;

class Shape {
public:
    virtual void display()=0;
    /*virtual void setValue() {

    }*/
    virtual void read() {

    }
    virtual double getArea() {
        return 1;
    }

};

class Circle : public Shape {
private:
    double PI = acos(-1);
    double radius;
    double area;

public:
    Circle():radius(0.0) {}
    Circle(double a) : radius(a) {}

    void read() {
        cout << "Enter radius of circle: " ;
        cin >> radius;
    }
    double getArea() {
        area = PI * radius * radius;
        return area;
    }
    void display() {
        cout << "Radius of Circle: " << radius << endl;
        cout << "Area of Circle: " << area << endl;
    }
};

class Square : public Shape {
private:
    double length;
    double area;

public:
    Square() : length(0.0) {}
    Square(double a) : length(a) {}

    void read() {
        cout << "Enter length of square: ";
        cin >> length;
    }
    double getArea() {
        area = length * length;
        return area;
    }
    void display() {
        cout << "Length of square: " << length<<endl;
        cout << "Area of square: " << area << endl;
    }
};




int main()
{
    Shape* S[SIZE];
    /*S[0] = new Circle(10.0);
    S[0]->getArea();
    S[0]->display();

    S[1] = new Square(10.0);
    S[1]->getArea();
    S[1]->display();*/
   ///***********************
   /* char choice;
        while(1) {
            cout << "Enter the type of shape you want." << endl
            << "Enter 1 for Circle." << endl
            << "Enter 2 for Square." << endl
            <<"Enter -1 to exit" << endl;
            cin >> choice;

            for(int i=0; i<SIZE; i++) {
                if(choice==-1) {
                break;
            }
            switch(choice)
            {
                case 1 : {
                    S[i] = new Circle();
                    S[i]->read();
                    break;
                }
            case 2 : {
                    S[i] = new Square();
                    S[i]->read();
                    break;
                }
            default: {
                    cout << "Invalid input." << endl;
                    break;
                }
            }
            }

        }


    for(int i=0; i<SIZE; i++) {
        S[i]->getArea();
    }

    for(int i=0; i<SIZE; i++) {
        S[i]->display();
    }*/
///**************************

    for(int i=0; i<SIZE; i+2) {
        S[i] = new Circle();
        S[i]->read();
    }
    for(int j=1; j<SIZE; j+2) {
        S[j] = new Square();
        S[j]->read();
    }

    for(int i=0; i<SIZE; i++) {
        S[i]->getArea();
        S[i]->display();
    }

    return 0;
}
