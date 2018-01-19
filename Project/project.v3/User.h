#include<iostream>
using namespace std;

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
