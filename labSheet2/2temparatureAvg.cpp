#include<iostream>
using namespace std;
class TempOfCities {
	float sum, avg;
	int temps[100][365];
public:
	void getTemp(){
		cout<<"\nEnter the temperature : ";
		for(int i=0;i<100;i++){
			for(int j=0;j<365;j++){
				cin>>temps[i][j];
			}
		}
	}
	void printAvg(){
		sum=0;
		for(int i=0;i<100;i++){
			for(int j=0;j<365;j++){
				sum += temps[i][j];
			}
			avg = sum/365.0;
			cout<<"\nAverage of city "<<i<<": "<<avg;
			sum = 0;
		}
	}
};
main(){
	TempOfCities t;
	t.getTemp();
	t.printAvg();
}
