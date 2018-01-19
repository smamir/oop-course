#include<iostream>

using namespace std;

int main()
{
    int a;
    double qty, retail_p, total_value=0;

    while(1)
    {
        cout << "\nEnter product number (-1 to end): ";
        cin >> a;
        if(a==-1)
            break;
        switch(a)
        {
            case 1:
                cout << "Enter quantity sold for one day:";
                cin >> qty;
                retail_p = qty*2.98;
                cout << "Retail Price for product 1 is $" << retail_p << endl;
                total_value=total_value+retail_p;
                break;

            case 2:
                cout << "Enter quantity sold for one day:";
                cin >> qty;
                retail_p = qty*4.50;
                cout << "\nRetail Price for product 2 is $" << retail_p << endl;
                total_value=total_value+retail_p;
                break;

            case 3:
                cout << "Enter quantity sold for one day:";
                cin >> qty;
                retail_p = qty*9.98;
                cout << "\nRetail Price for product 3 is $" << retail_p << endl;
                total_value=total_value+retail_p;
                break;

            case 4:
                cout << "Enter quantity sold for one day:";
                cin >> qty;
                retail_p = qty*4.49;
                cout << "\nRetail Price for product 4 is $" << retail_p << endl;
                total_value=total_value+retail_p;
                break;

            case 5:
                cout << "Enter quantity sold for one day:";
                cin >> qty;
                retail_p = qty*6.87;
                cout << "\nRetail Price for product 1 is $" << retail_p << endl;
                total_value=total_value+retail_p;
                break;

            default:
                cout << "Invalid product number!" << endl;
                break;

        }
    }

    cout << "\nTotal retail value of all products sold: $" << total_value << endl;


    return 0;
}
