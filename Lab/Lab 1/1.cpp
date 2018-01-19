#include<iostream>

using namespace std;

int main()
{
    int a,b,i=0,sum=0;
    cout << "Enter integer range: " << endl;
    cin >> a;
    cin >> b;

    for(i=a; i<=b; i++)
    {
        if(i%2!=0)
        {
            sum=sum+i;
        }
    }
    cout << "Summation of all odd integers in the range " << a << " to " << b << ": " << sum << endl;

    return 0;
}
