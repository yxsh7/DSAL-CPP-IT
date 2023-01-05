/*
SI32 Yash Kamthe
GITHUB: https://github.com/yxsh7
Department maintains students database. File contains roll no., name, division and address.
Write a program to create a sequential file to store
and maintain student data. It should allow the user to add, delete
information of student. Display information of particular student. If
record of student does not exist an appropriate message is displayed. If
student record is found it should display the student details.
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
    int roll_number;
    char name[50], address[200], divison[5];

    public:
            void get_data()
            {
                cout<<"\nEnter Roll Number: ";
                cin>>roll_number;
                cout<<"\nEnter Name: ";
                cin>>name;
                cout<<"\nEnter Division: ";
                cin>>divison;
                cout<<"\nEnter Address: ";
                cin>>address;
            }
            void show_data()
            {
                cout<<"\n"<<roll_number<<"\t\t"<<name<<"\t"<<divison<<"\t\t"<<address;
            }
            int return_roll()
            {
                return roll_number;
            }
};

class seq_file
{
    char file_name[100];

    public:
        void create_database();
        void display_data();
        void add_data();
        void remove_data(int);
        void search_data(int);
};

void seq_file::create_database()
{
        ofstream fp; // ofstream : create and write infomation
        student s;
        cout<<"\nEnter File Name: ";
        cin>>file_name;
        fp.open(file_name);
        s.get_data();
        fp.write((char*)&s,sizeof(s));
        fp.close();
}

void seq_file::display_data()
{
    ifstream fp;
    student s;
    fp.open(file_name);
    cout<<"\nRoll Number\tName\tDivision\tAddress";
    fp.read((char*)&s,sizeof(s));

    while(!fp.eof())
    {
        s.show_data();
        fp.read((char*)&s,sizeof(s));
    }
    fp.close();
}

void seq_file::add_data()
{
    ofstream fp;
    student s;

    fp.open(file_name,ios::app); //open in append mode
    s.get_data();
    fp.write((char*)&s,sizeof(s));
    fp.close();
}

void seq_file::remove_data(int key)
{
    ifstream f1;
    ofstream f2;
    student s;
    int flag = 0;
    f1.open(file_name);
    f2.open("second.txt");
    f1.read((char*)&s,sizeof(s));

    while(!f1.eof())
    {
        if(key==s.return_roll())
        {
            s.show_data();
            flag=1;
        }
        else 
            f2.write((char*)&s,sizeof(s));
        
    f1.read((char*)&s,sizeof(s));
    }

    if(flag==0)
        cout<<"Record not Found";
    f1.close();
    f2.close();
    remove(file_name);
    rename("second.txt",file_name);
}

void seq_file::search_data(int key)
{
    ifstream fp;
    student s;
    int flag = 0;
    fp.open(file_name);
    fp.read((char*)&s,sizeof(s));

    while(!fp.eof())
    {
        if(key==s.return_roll())
        {
            flag = 1;
            break;
        }
        fp.read((char*)&s,sizeof(s));
    }

    if(flag==0)
        cout<<"Record not found";
    else 
        s.show_data();
    
    fp.close();
}

int main()
{
    int choice, input;
    seq_file obj;

    while(true)
    {
    cout<<"\n1. Create Database \n2.Display \n3.Add a Record \n4.Delete a Record \n5.Search a Record\n6.Exit";
    cout<<"\nEnter Your Choice: ";
    cin>>choice;
        switch(choice)
        {
            case 1:
                obj.create_database();
                break;
            case 2:
                obj.display_data();
                break;
            case 3:
                obj.add_data();
                break;
            case 4:
                cout<<"Enter Roll Number of Student: ";
                cin>>input;
                obj.remove_data(input);
                break;
            case 5:
                cout<<"Enter Roll number to Search: ";
                cin>>input;
                obj.search_data(input);
                break;
            case 6:
                return -1;
        }
    }
}