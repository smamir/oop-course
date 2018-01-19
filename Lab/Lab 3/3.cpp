#include<iostream>

using namespace std;

struct length
{
    double feet;
    double inch;
};

struct width
{
    double feet;
    double inch;
};

struct dimension
{
    struct length l;
    struct width w;
    double area;
};

double calculateArea(struct dimension d)
{
    double t_l_feet, t_w_feet, area;
    t_l_feet = d.l.feet + (d.l.inch/12);
    t_w_feet = d.w.feet + (d.w.inch/12);
    area = t_l_feet * t_w_feet;
    return area;
}

int main()
{
    struct dimension R;
    cout << "Enter length(feet-inch): ";
    cin >> R.l.feet >> R.l.inch;
    cout << "Enter width(feet-inch): ";
    cin >> R.w.feet >> R.w.inch;
    R.area = calculateArea(R);
    cout << "Total area: " << R.area;

    return 0;
}
