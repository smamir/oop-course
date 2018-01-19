#include<iostream>
#include<iomanip>

using namespace std;

struct mileage
{
    double gallons_used;
    double miles_driven;
    double miles_per_gallon;
};

int main()
{
    struct mileage M[50];
    double total_gu=0,total_md=0, avg_mpg;

    cout.setf(ios::fixed);

    for(int i=0; i<50; i++)
    {
        cout << "Enter the gallons used (-1 to end): ";
        cin >> M[i].gallons_used;
        if(M[i].gallons_used==-1)
        {
            break;
        }
        else
        {
            cout << "Enter the miles driven: ";
            cin >> M[i].miles_driven;
        }

        M[i].miles_per_gallon=M[i].miles_driven/M[i].gallons_used;

        cout << "The miles / gallon for this tank was " << setprecision(6) <<M[i].miles_per_gallon << endl <<endl;

        total_gu=total_gu+M[i].gallons_used;
        total_md=total_md+M[i].miles_driven;
    }
    avg_mpg=total_md/total_gu;

    cout << "\nThe overall average miles/gallon was " << avg_mpg << endl;

    return 0;
}
