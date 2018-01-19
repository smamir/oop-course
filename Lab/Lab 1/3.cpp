#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int A[10],i,mx=0,mn=999999;
    float avg,sum=0;

    cout << "Enter ten integer:" << endl;
    for(i=0; i<10; i++)
    {
        cin >> A[i];
    }

    for(i=0; i<10; i++)
    {
        sum=sum+A[i];
        if(A[i]>=mx)
        {
            mx=A[i];
        }
        if(A[i]<=mn)
        {
            mn=A[i];
        }
    }
    avg=sum/10;

    cout << setw(14) << left << "Maximum: " << mx << endl
    << setw(14) << left << "Minimum: " << mn << endl
    << setw(14) << left << "Sum    : " << sum << endl
    << setw(14) << left << "Average: " << avg << endl;

    return 0;
}
