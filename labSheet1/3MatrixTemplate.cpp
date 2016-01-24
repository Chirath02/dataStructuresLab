#include <iostream>
#include <iomanip>

using namespace std;

template <class T>

void addition(T A[], T B[],int m,int n,int p,int q) {
	if(m==p && n==q) {
		cout << "Sum = " << endl; 
		for(int i=0;i<m;++i) {
			for(int j=0;j < n;++j) {
				cout <<setw(4)<< A[i][j] + B[i][j] ; 
			}
			cout << endl;
		}
	}
	else {
		cout << "Error matrixes should be equal" <<endl;
	}
}

template <class T>

void subtraction(T A[], T B[],int m,int n,int p,int q) {
	if(m==p && n==q) {
		cout << "Diffrence = " << endl; 
		for(int i=0;i<m;++i) {
			for(int j=0;j < n;++j) {
				cout <<setw(4)<< A[i][j] - B[i][j] ; 
			}
			cout << endl;
		}
	}
	else {
		cout << "Error matrixes should be equal" <<endl;
	}
}

template <class T>

void multiplication(T A[], T B[],int m,int n,int p,int q) {
	int s;
	if(n==p) {
		cout << "Product = " << endl; 
		for(int i=0;i<m;++i) {
			s=0;
			for(int j=0;j < n;++j) {
				for(int k=0;k< n;++k) {
					s += A[i][j] * B[k][j];
				}cout <<setw(4)<<s; 
			}
			cout << endl;
		}
	}
	else {
		cout << "Error matrixes should be equal" <<endl;
	}
}

template <class T>

void input(T *a, T *b,int m,int n,int p,int q) {
	cout << "Enter matrix 1" << endl;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			cin >> a[i][j];
		cout << "Enter matrix 2" << endl;
	for(int i=0;i<p;++i)
		for(int j=0;j<q;++j)
			cin >> b[i][j];
}

main() {
	int choice, a[100][100], b[100][100];
	float c[100][100], d[100][100];
 	double e[100][100], f[100][100];
	int m, n, p, q;
	cout << "Enter number of elememts for first matrix : ";
	cin >> m >> n;
	cout << "Enter number of elememts for second matrix : ";
	cin >> p >> q;
	cout << "Enter 1 for int " << endl;
	cout << "Enter 2 for float " << endl;
	cout << "Enter 3 for double " << endl;
	cin >> choice;
	if(choice == 1) {
		input(a,b,m,n,p,q);
		addition(a,b,m,n,p,q);
		subtraction(a,b,m,n,p,q);
		multiplication(a,b,m,n,p,q);
	}
	else
		if(choice == 2) {
			input(c,d,m,n,p,q);
			addition(c,d,m,n,p,q);
			subtraction(c,d,m,n,p,q);
			multiplication(c,d,m,n,p,q);
		}
		else
			if(choice == 3) {
				input(e,f,m,n,p,q);
				addition(e,f,m,n,p,q);
				subtraction(e,f,m,n,p,q);
				multiplication(e,f,m,n,p,q);
			}
			else
				cout << "Error : wrong option ";
}