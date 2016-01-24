#include <iostream>

using namespace std;

class Employee {
protected:
	char name[100];
public:
	Employee() {
		cout << "Employee class " << endl;
	}
};

class Programmer:public Employee {
protected:
	int salary;
public:
	Programmer() {
		salary = 2000;	
		cout << "Programmer class" << endl;
	}
};

class TeamLead:public Employee {
protected:
	int salary;
public:
	TeamLead(){
		salary = 1000;	
		cout << "Team Lead class" << endl;
	}
};

class Manager:public Employee {
protected:
	int salary;
public:
	Manager() {
	  salary = 1000;	
	  cout << "Manager class " << endl;
	}
};

class HRManager:public Manager {
protected:
	string type[100];
public:
	HRManager() {
		cout << "HR manager class" << endl;
	}
};

class ProjectManager:public Manager {
protected:
	string type[100];
public:
	ProjectManager() {
		cout << "ProjectManager class" << endl;
	}
};

main() {
	Employee E;
	cout << endl << endl;
	Programmer P;
	cout << endl << endl;
	TeamLead T;
	cout << endl << endl;
	Manager M;
	cout << endl << endl;
	HRManager H;
	cout << endl << endl;
	ProjectManager Pm;
}