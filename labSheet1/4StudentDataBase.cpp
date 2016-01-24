#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
protected:
	string studentName, dateOfBirth;
	string qualification;
	float markOfSuject[5], total, average;
public:
	Student() {
		total = average =0;
	}
	void getDetails() {
        ofstream file("stud.dat", ios::binary|ios::app);
		cout << "Enter student name :";
        cin >> studentName;
        cout << "Enter date of birth ;";
        cin >> dateOfBirth;
        cout << "Enter qualification :";
        cin >> qualification;
        cout << "Enter the marks of 5 subjects:";
        for(int i = 0; i < 5;++i) {
            cin >> markOfSuject[i];
            total += markOfSuject[i];
        }
        average = total/5;
        file.write((char *)this,sizeof(*this));
        file.close();
	}
	void modify() {
		
	}
	void display() {
        float avg;
        cout << "Enter lower bound average to display from " ;
        cin >> avg;
		ifstream file("stud.dat", ios::binary);
        
        while(file.read((char *)this,sizeof(*this)) && this->average > avg) {
            cout << endl << "Name : " << studentName << endl;
            cout << "D.O.B. : " << dateOfBirth << endl;
            cout << "Qualification : " << qualification << endl;
            cout << "Total = " << total << endl;
            cout << "Average = " << average << endl;
            
        }
        file.close();
    }
};

int main() {
    Student S;
//     S.getDetails();
    S.display();
    return 0;
}