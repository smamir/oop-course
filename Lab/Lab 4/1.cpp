#include<iostream>

using namespace std;

struct weight
{
    double pounds;
    double ounces;
};

void addWeights(struct weight a, struct weight b)
{
    double p=0, o=0;
    p=a.pounds+b.pounds;
    o=a.ounces+b.ounces;
    if(o>=16)
    {
        p=p+1;
        o=o-16;
    }
    cout << "Sum of weights: " << p << " pounds " << o << " ounces" << endl;

}

void subWeights(struct weight a, struct weight b)
{
    double p=0, o=0;
    p=a.pounds-b.pounds;
    o=a.ounces-b.ounces;

    if(o<0)
    {
        p=p-1;
        o=o+16;
    }

    cout << "Difference of weights: " << p << " pounds " << o << " ounces" << endl;
}

int main()
{
    struct weight a, b;

    cout << "Enter weight of first product: ";
    cin >> a.pounds >> a.ounces;
    cout << "Enter weight of second product: ";
    cin >> b.pounds >> b.ounces;

    addWeights(a,b);
    subWeights(a,b);

    return 0;
}
