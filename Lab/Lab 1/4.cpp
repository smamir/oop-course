#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    int m,n,i,j,sum=0,sum_t=0;
    cout << "Enter 2D array size and values: " << endl;
    cin >> m >> n;

    int A[3][3];

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> A[i][j];
        }
        cout << endl;
    }


    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            sum=sum+A[i][j];
        }
        cout << "Row " << i << " sum: " << setw(15) << right << sum <<endl;
        sum=0;
    }

    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            sum=sum+A[i][j];
        }
        cout << "Column " << j << " sum: " << setw(12) << right << sum <<endl;
        sum = 0;
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            sum_t=sum_t+A[i][j];
        }
    }
    cout << "Total sum: " << setw(15) << right << sum_t << endl;



    return 0;
}
