//Airline Reservations System

#include<iostream>
using namespace std;

int capacity[10] = {0};

int main()
{
    int option,option2,total_seat=10,f=0,e=0;
    while(total_seat>0)
    {
        cout<<"Please type 1 for 'first class'"<<endl;
        cout<<"Please type 2 for 'economy'"<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                for(int i=0;i<5;i++)
                {
                    if(capacity[i]==0)
                    {
                        capacity[i]=1;
                        total_seat--;
                        f++;
                        cout<<"\n____boarding pass____"<<endl;
                        cout<<"Seat No. "<<i+1<<" "<<"Section: first class\n\n"<<endl;
                        break;
                    }

                    if(f==5)
                        {
                            cout<<"First class section is full."<<endl;
                            cout<<"Would you like to be transferred to economy?\n1 for Yes, 2 for no:";
                            cin>>option2;
                            if(option2==1)
                            {
                                for(int i=5;i<10;i++)
                                {
                                    if(capacity[i]==0)
                                    {
                                        capacity[i]=1;
                                        total_seat--;
                                        e++;
                                        cout<<"\n____boarding pass____"<<endl;
                                        cout<<"Seat No. "<<i+1<<" "<<"Section: economy class\n\n"<<endl;
                                        break;
                                    }
                                    if(e==5)
                                    {
                                        cout<<"No more seat available."<<endl;
                                        break;
                                    }
                                }
                            }
                            else if(option2==2)
                            {
                                cout<<"Next flight leaves in 3 hours."<<endl;
                                break;
                            }

                        }
                }
                break;

            case 2:
                for(int i=5;i<10;i++)
                {
                    if(capacity[i]==0)
                    {
                        capacity[i]=1;
                        total_seat--;
                        e++;
                        cout<<"\n____boarding pass____"<<endl;
                        cout<<"Seat No. "<<i+1<<" "<<"Section: economy class\n\n"<<endl;
                        break;
                    }

                    if(e==5)
                        {
                            cout<<"Economy class section is full."<<endl;
                            break;
                        }
                }
                break;

            default:
                cout<<"\nWrong Input\n\n"<<endl;
        }
        if(total_seat==0)
            cout<<"\n\nNo more seat on the plane!"<<endl;
    }
    return 0;
}
