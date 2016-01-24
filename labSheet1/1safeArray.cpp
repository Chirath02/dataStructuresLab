#include <iostream>

using namespace std;

class SafeArray {
	int arr[100];
	int index,size;
	int lower;
public:
	SafeArray(int l,int u) {
		index = 0;
		label:
		size = u - l;
		try {
			if(size > 100) {
					throw(100);
			}
			else {
				lower = l;
			}
		}
		catch(int n) {
			cout << "Size of array cannot be more than " << n << endl;
			cout << "Enter new lower bound and upper bound : " ;
			cin >> u >> l ;
			size = u - l;
			lower = l;
			goto label;
		}
	}
	void input(int ele) {
		try {
			if(index > size) {
				throw;
			}
			else {
				arr[index++] = ele;
			}	
		}
		catch(...) {
			cout << "Error ,Out of bounds " << endl;
		}
	}
	void print() {
		for(int i = 0;i < index ;++i) {
			cout << "arr[" << i + lower << "] = " << arr[i] << " " << endl;
		}
	}
};

main() {
	int l,u,ele;
	cout << "Enter lower and upper bounds :";
	cin >> l >> u;
	cout << "Enter array elements : " << endl;
	SafeArray array(l,u);
	for(int i=0;i<u-l;++i) {
		cin >> ele;
		array.input(ele);
	}
	array.print();
}