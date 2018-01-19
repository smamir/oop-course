#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int sales[4][5], i ,j, r_total=0, c_total=0;

     for(i=0; i<4; i++)
    {
        for(j=0; j<5; j++)
        {
            cin >> sales[i][j];
        }
    }



    cout << setw(10) << "Product 1" << setw(10) << "Product 2"
    << setw(10) << "Product 3" << setw(10) << "Product 4"
    << setw(10) << "Product 5" <<  setw(10) << "Total" << endl;
    for(i=0; i<4; i++)
    {
        r_total=0;
        for(j=0; j<5; j++)
        {
            r_total=r_total+sales[i][j];
            cout << setw(10) << sales[i][j];
        }
        cout << setw(7) << r_total;
        cout << endl;
    }

    for(j=0; j<5; j++)
    {
        c_total=0;
        for(i=0; i<4; i++)
        {
            c_total=c_total+sales[i][j];
        }
        cout << setw(10) << c_total;
    }


    return 0;
}
