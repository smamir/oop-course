#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include"Others.h"
#include"User.h"
#include"Admin.h"

using namespace std;

int main() {

    admin_data ad;
    user_data us;

    greetings();
    int choice = main_menu();
    while(choice!=3) {

        if(choice==1) {
            cout << "\nPlease Enter Your Credentials to Login As Administrator." << endl;
            if(ad.admin_login()==1) {

                cout<<"\nAdmin Login Successful!"<<endl;
                int admin_login_status=0;
                while(admin_login_status!=1) {

                    switch(ad.control_panel()) {

                        case 1:ad.add_fileinfo();
                            break;

                        case 2:ad.edit_fileinfo();
                            break;

                        case 3:ad.view_fileinfo();
                            break;

                        case 4:admin_login_status=1;
                            cout<<"\nLogged Out!\n"<<endl;;
                            break;

                        default:
                            break;

                    }
                }

            }

        }

        else if(choice==2) {
            int c;
            cout << "\nYou Have Accessed as General User." << endl
            << "Available Actions: " << endl
            << "1.Search for a Contact." << endl
            << "2.Go to Main Menu."
            << "\nSelect A Task: ";
            cin >> c;
            if(c==1) {
                us.search_info();
            }
            else if(c==2) {
                cout << "\nReturning to Main Menu." << endl;
            }
            else {
                cout << "Invalid Operation!" << endl;
            }

        }

        else {
            cout << "\nInvalid Operation! Please Try Again. " << endl;
        }

        choice = main_menu();
    }

    return 0;
}
