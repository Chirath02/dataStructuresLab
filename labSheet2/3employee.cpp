#include<iostream>
using namespace std;

class Employee
{
string lastname[20],firstname[20];
double hourly_wage[20];
int years_with_company[20];
public:
void getdata(int n)
{
for(int i=0;i<n;i++)
{
cout<<"Employee"<<i+1<<":\n";
cout<<"last name?";
cin>>lastname[i];
cout<<"First name?";
cin>>firstname[i];
cout<<"hourly wage";
cin>>hourly_wage[i];
cout<<"years with company?";
cin>>years_with_company[i];
}
}
void sorting(int n) {
int i,j,key;
string keyfn,keyln;
double keyhw;
 for(j=1;j<n;j++) {
                key = years_with_company[j];
                keyfn = firstname[j];
                keyln = lastname[j];
                keyhw = hourly_wage[j];
                i=j-1;
                while(i>-1 && years_with_company[i]<key) {
                   years_with_company[i+1] = years_with_company[i];
                    firstname[i+1] = firstname[i];
                    lastname[i+1] = lastname[i];
                    hourly_wage[i+1] = hourly_wage[i];
                    i--;
                }
                years_with_company[i+1] = key;
                firstname[i+1] = keyfn;
                lastname[i+1] = keyln;
                hourly_wage[i+1] = keyhw;
            }
        }
void disp(int n)
{
 cout<<"On the basis of years of company,sorted info is \n";
            cout<<"First Name           Last Name           Hourly Wage         Years With Company"<<endl;
            for(int i = 0; i < n; i++)
                cout<<firstname[i]<<"            "<<lastname[i]<<"           "<<hourly_wage[i]<<"         "<<years_with_company[i]<<"\n";
        }

}e;


int main()
{
int n;
cout<<"Enter the no of employees";
cin>>n;
cout<<"Enter the details";
e.getdata(n);
cout<<"Sorting...";
e.sorting(n);
e.disp(n);
}
