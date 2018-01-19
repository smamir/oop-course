#include<iostream>

using namespace std;

int main()
{
    int seat[10]={0},n,i,j, first=0, eco=0;
    char ch;

    while(1)
    {
        cout << "Please type 1 for first class" << endl;
        cout << "Please type 2 for economy" << endl;
        cin >> n;
        if(n==1)
        {
            for(i=0; i<5; i++)
            {
                if(seat[i]==0)
                {
                    seat[i]=1;
                    first++;
                    cout << "Seat number: " << i+1 << endl;
                    cout << "Seat type: first class" << endl;
                    break;
                }
                if(first ==5)
                {
                    cout << "First class seat is not available. Do you want a economy seat?(y/n)" << endl;
                    cin >> ch;
                    if(ch=='y')
                    {
                        for(j=5; j<10; j++)
                        {
                            if(seat[j]==0)
                            {
                                seat[j]=1;
                                eco++;
                                cout << "Seat number: " << j+1 << endl;
                                cout << "Seat type: economy" << endl;
                                break;
                            }
                        }
                }
                    else
                    {
                        cout << "\nNext flight leaves in 3 hours." << endl;
                    }
                }

            }

        }

        else if(n==2)
        {
            for(j=5; j<10; j++)
            {
                if(seat[j]==0)
                {
                    seat[j]=1;
                    eco++;
                    cout << "Seat number: " << j+1 << endl;
                    cout << "Seat type: economy" << endl;
                    break;
                }
                if(eco ==5)
                {
                    cout << "Economy seat is not available. Do you want a first class seat?(y/n)" << endl;
                    cin >> ch;
                    if(ch=='y')
                    {
                        for(j=0; j<5; j++)
                        {
                            if(seat[j]==0)
                            {
                                seat[j]=1;
                                first++;
                                cout << "Seat number: " << j+1 << endl;
                                cout << "Seat type: first class" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "\nNext flight leaves in 3 hours." << endl;
                    }
                }
            }
        }
        else
        {
            cout << "Invalid seat type!" << endl;
        }


    }

    return 0;
}
