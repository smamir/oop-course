#include<iostream>
using namespace std;

char file_name[15]={"userdata.txt"};

void greetings() {
    cout<< "\n**************************************"<< endl;
    cout<< "..::Welcome To Telephone Directory::.."<< endl;
    cout<< "**************************************"<< endl;
}

int main_menu() {

    int choice;
    cout << "\nEnter 1 for Administrator Login." << endl;
    cout << "Enter 2 for General User." << endl;
    cout << "Enter 3 for Program Termination." << endl;
    cout << "Select A Task: " ;
    cin >> choice;
    return choice;
}
