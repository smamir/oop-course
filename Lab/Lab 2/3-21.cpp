#include<iostream>
#include<iomanip>

using namespace std;

struct employee
{
    int hour;
    double rate;
    double salary;
};

int main()
{
    struct employee E[50];
    int i;

    cout.setf(ios::fixed);

    for(i=0; i<50; i++)
    {
        cout << "Enter # of hours worked (-1 to end): ";
        cin >> E[i].hour;
        if(E[i].hour==-1)
        {
            break;
        }
        else
        {
            cout << "Enter hourly rate of the worker ($00.00): ";
            cin >> E[i].rate;
        }

        if(E[i].hour<=40)
        {
            E[i].salary=E[i].hour*E[i].rate;
        }
        else
        {
            E[i].salary=(40*E[i].rate)+(E[i].hour-40)*E[i].rate*1.5;
        }
        cout << "Salary is $" << setprecision(2) << E[i].salary << endl << endl;
    }

    return 0;
}
