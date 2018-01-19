#include<iostream>
using namespace std;

class admin_data : public user_data
{
    protected:
        string username;
        string password;
        string sample_username;
        string sample_password;

    public:
        admin_data();
        int admin_login();
        void add_fileinfo();
        int getsizeofFile();
        void edit_fileinfo();
        void view_fileinfo();
        int control_panel();
};

///No argument constructor.
///Class : admin_data
///Sets default admin login credentials.

admin_data::admin_data()
{
    username="admin";
    password="1234";
}

///Function : admin_login
///Class : admin_data
///Authenticates Administrator login.

int admin_data::admin_login()
{
    cout<<"\nID:";
    cin>>sample_username;
    cout<<"Password:";
    cin>>sample_password;
    if(username==sample_username && password==sample_password) {
        return 1;
    }
    else {

        cout<<"\nID/Password Incorrect! Returning to Main Menu." << endl;
        return 0;

    }
}

///Function : control_panel
///Class : admin_data
///Shows available operations for administrator account.

int admin_data::control_panel()
{
    ///greetings();
    int ch;
    cout<<"\n.::Administrator Control Panel::."<<endl;
    cout<<"1.Add A New User Account."<<endl;
    cout<<"2.Edit An Existing Account Info."<<endl;
    cout<<"3.View All Available Account Info."<<endl;
    cout<<"4.Log Out"<<endl;
    cout<<"\nSelect a Task:";
    cin>>ch;
    ///system("cls");
    return ch;
}

///Function : getsizeofFile
///Class: admin_data
///Returns the size of the file.

int admin_data::getsizeofFile()
{
     return user_data::getsizeofFile();
}

///Function : add_fileinfo
///Class : admin_data
///Adds a new user account to file.

void admin_data::add_fileinfo()
{
    user_data obj4;
    fstream file(file_name,ios::app|ios::out);
    obj4.get_detail();
    file.write((char*)&obj4,sizeof(obj4));
    file.close();

    char ch;
    cout << "Do You Want to Add Another Account?(y/n):";
    cin >> ch;
    if(ch=='y') {

        add_fileinfo();
    }
    else if(ch=='n') {

        cout << "\nReturning to Control Panel." << endl;
    }
    else {
        cout << "\nInvalid Choice.Returning to Control Panel. " << endl;
    }

}

///Function : view_fileinfo
///Class : admin_data
///Shows all available user account information.

void admin_data::view_fileinfo()
{
    user_data obj5;
    int size=getsizeofFile();
    ifstream infile(file_name);
    if(infile==NULL)
    {
        cout<<"\n\tNo Record Found!"<<endl;
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            infile.read((char*)&obj5,sizeof(obj5));
            obj5.show_detail();
            cout<<"\n";
        }
    }
    infile.close();
}

///Function : edit_fileinfo
///Class : admin_data
///Edit an existing account.

void admin_data::edit_fileinfo()
{
    user_data obj6;
    int size=getsizeofFile();
    ifstream infile(file_name);
    if(infile==NULL)
    {
        cout<<"\t\nNo Record Found!"<<endl;
    }
    infile.close();
    fstream file(file_name,ios::ate|ios::out|ios::in);
    file.seekg(0);
    int id;
    int counter=0;
    cout<<"\n\tEnter The User's ID:";
    cin>>id;
    if(file==NULL)
    {
        cout<<"\n\tNo Record Found!\n"<<endl;

    }
    else
    {
        for(int i=0;i<size;i++)
        {
            file.read((char*)&obj6, sizeof(obj6));
            if(id==obj6.id)
            {
                int size=file.tellg();
                size=size-sizeof(obj6);
                file.seekp(size,ios::beg);
                user_data newobj=obj6;
                newobj.get_detail();
                file.write((char*)&newobj,sizeof(newobj));
                counter=1;
                break;
            }
            cout<<"\n";
        }
    }
    file.close();
    if(counter==0)
    {
        cout<<"\n\tNo Record Found\n"<<endl;
    }
    else
    {
        cout<<"\n\tDatabase Updated Successfully!\n"<<endl;
    }

    char ch;
    cout << "Do You Want to Edit Another Account?(y/n):";
    cin >> ch;
    if(ch=='y') {

        edit_fileinfo();
    }
    else if(ch=='n') {

        cout << "\nReturning to Control Panel." << endl;
    }
    else {
        cout << "\nInvalid Choice.Returning to Control Panel. " << endl;
    }

}
