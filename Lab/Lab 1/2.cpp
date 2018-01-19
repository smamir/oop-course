#include<iostream>

using namespace std;

int main()
{
    int a,b,i,sum=0, c;

    cout << "Enter the range: " << endl;
    cin >> a;
    cin >> b;
    c=1;
    for(i=a; i<=b; i++)
    {
        if(i%2!=0)
        {
            if(c==1)
            {
                sum=sum+i;
            }
            else if(c%2!=0)
            {
                sum=sum+i;
            }
            else if(c%2==0)
            {
                sum=sum-i;
            }
            c++;
        }
    }
    cout << "Result: " << sum;

    return 0;
}
