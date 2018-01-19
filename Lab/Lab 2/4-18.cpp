#include<iostream>

using namespace std;

int main()
{
    int a[5],i,j;

    cout << "Enter five integer (between 1 to 30)" << endl;
    for(i=0; i<5; i++)
    {
        cin >> a[i];
        for(j=0; j<a[i]; j++)
        {
            cout << "*";
        }
        cout << endl;

    }

    return 0;
}
