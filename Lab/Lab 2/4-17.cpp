#include<iostream>

using namespace std;

struct customer
{
    int ac_no;
    double cr_limit;
    double balance;
};

int main()
{
    struct customer C[3]={{100,2000,500}, {101,5000,3000}, {102,6000, 3000}};
    int i;
    double new_cr_limit;

    for(i=0; i<3; i++)
    {
        new_cr_limit=C[i].cr_limit/2;
        cout << "New credit limit for account number " << C[i].ac_no << " is $" << new_cr_limit << endl ;

        if(C[i].balance > new_cr_limit)
        {

            cout << "\nAccount number: " << C[i].ac_no << endl
            << "New credit balance exceeded by $" << C[i].balance-new_cr_limit << endl << endl;
        }
    }

    return 0;
}
