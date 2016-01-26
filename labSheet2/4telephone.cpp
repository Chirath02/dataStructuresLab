#include<iostream>
#include<string>
using namespace std;

class telephone
{
    public:  long double num;
             string fn, ln;
             void getdata()
             {
                 cout<<"Enter Phone Number: "<<endl;
                 cin>>num;
                 cout<<"Enter First Name: "<<endl;
                 cin>>fn;
                 cout<<"Enter Last Name: "<<endl;
                 cin>>ln;
             }
             void display()
             {
                 cout<<"Phone Number: "<<num<<endl;
                 cout<<"First Name: "<<fn<<endl;
                 cout<<"Last Name: "<<ln<<endl;
             }
};
int main()
{
    telephone a[100];
    int n;
    string p;
    cout<<"How many insertions are to be made? \n";
    cin>>n;
    for(int i = 0; i < n;i++)
    {
        a[i].getdata();
    }
    cout<<"Enter Name to be searched: \n";
    cin>>p;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(p == a[i].fn || p == a[i].ln)
        {
            flag++;
            a[i].display();
        }
    }
    if(flag == 0)
    {
        cout<<"Name not Found. \n";
    }
    return 0;
}

