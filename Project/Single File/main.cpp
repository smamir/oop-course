#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

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

class user_data
{
protected:
    char cell_num[12];
    char tele_num[15];
    char user_name[25];
    char city[25];
    char area[25];

public:
    int id;
    user_data() {}
    ~user_data() {}

    void get_detail();
    void show_detail();
    void search_info();
    int getsizeofFile();
};

///Function : get_detail////
///Class : user_data///////
///Takes information to create a new user account.

void user_data::get_detail()
{
    cout<<"\nEnter User ID:";
    cin>>id;
    cout<<"\nEnter Mobile number:";
    cin>>cell_num;
    cout<<"\nEnter Telephone Number:";
    cin>>tele_num;
    cin.ignore();
    cout<<"\nEnter User Name:";
    gets(user_name);
    cout<<"\nEnter City Name:";
    gets(city);
    cout<<"\nEnter Area Name:";
    gets(area);
    cout<<"\nUser Account Created!"<<"\n"<<endl;
}

///Function : show_detail///
///Class: user_data/////////
///Displays all information of an user account.


void user_data::show_detail()
{
    cout<<"\n\tID:"<<id<<endl;
    cout<<"\tName:"<<user_name<<endl;
    cout<<"\tMobile Number:"<<cell_num<<endl;
    cout<<"\tTelephone Number:"<<tele_num<<endl;
    cout<<"\tCity:"<<city<<endl;
    cout<<"\tArea:"<<area<<endl;
}

///Function : getsizeofFile
///Class : user_data
///Returns the size of the file.

int user_data::getsizeofFile()
{

    int size;
    int total;
    user_data obj1;
    ifstream infile(file_name);
    infile.seekg(0,ios::end);
    total=infile.tellg();
    infile.close();
    size=total/sizeof(obj1);
    return (size);
}

///Function : search_info
///Class : user_data
///Search for an user account with ID or Name.

void user_data::search_info()
{

    user_data obj2;
    int id=0,choice;
    int counter=0;
    char name[25];
    int size=getsizeofFile();

    ifstream infile(file_name);
    if(infile==NULL)
    {
        cout<<"\n\tNo Record Found!"<<endl;
    }
    infile.close();
    while(1)
    {
    cout<<"\n"<<endl;
    cout<<"\tAvailable Search Criteria.";
    cout<<"\n\t1.Search With ID."<<endl;
    cout<<"\t2.Search With Name."<<endl;
    cout<<"\n\tSelect a Task:";
    cin>>choice;
    if(choice==1)
    {
        cout<<"\n\tInput the User's ID:";
        cin>>id;
        ifstream infile(file_name);
        if(infile==NULL)
        {
            cout<<"\n\tNo Record Found!"<<endl;
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                infile.read((char *)&obj2,sizeof (obj2));
                if(id==obj2.id)
                {
                    obj2.show_detail();
                    counter=1;
                }
                cout<<"\n";
            }
          infile.close();
          if(counter==0)
          {
             cout<<"\n\tNo Record Found!"<<endl;
          }
        }
    }
    else if(choice==2)
    {
        cout<<"\n\tInput the User's Name:";
        cin >> name;
        ifstream infile(file_name);
        cout<<"\n";
        if(infile==NULL)
        {
            cout<<"\n\tNo Record Found!"<<endl;
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                infile.read((char *)&obj2,sizeof (obj2));
                if(!strcmp(obj2.user_name,name))
                {
                    obj2.show_detail();
                    counter=1;
                }
                cout<<"\n";
            }
          infile.close();
          if(counter==0)
          {
             cout<<"\n\tNo Record Found!"<<endl;
          }
        }

    }
    else
        cout<<"\n\tInvalid Input!"<<endl;
        break;

    }

    char ch;
    cout << "Do You Want to Search for Another Account?(y/n):";
    cin >> ch;
    if(ch=='y') {

        search_info();
    }
    else if(ch=='n') {

        cout << "\nReturning to Main Menu." << endl;
    }
    else {
        cout << "\nInvalid Choice. Returning to Main Menu. " << endl;
    }
}


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
    int ch;
    cout<<"\n.::Administrator Control Panel::."<<endl;
    cout<<"1.Add A New User Account."<<endl;
    cout<<"2.Edit An Existing Account Info."<<endl;
    cout<<"3.View All Available Account Info."<<endl;
    cout<<"4.Log Out"<<endl;
    cout<<"\nSelect a Task:";
    cin>>ch;
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
