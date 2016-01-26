#include <iostream>
#include <cstring>


using namespace std;

class MyStack {
	char arr[200];
	int top, size;
public:
	MyStack() :top(-1), size(200){
	}
	
	void push(char x) {
		if(top >= size)
			cout << "Stack Overflow" << endl;
		else
			arr[++top] = x;
	}
	
	char pop() {
		if(top == -1) {
			cout << "Stack Underflow" << endl;
		}
		else
			return arr[top--];
	}
	
	bool isEmpty() {
		if(top == -1)
			return 1;
		return 0;
	}
	
	int topIs() {
		return top;
	}
	
	char getTop() {
		return arr[top];
	}
};

class VariableMap {
private:
	float val[26];
	int v;
public:
	VariableMap() {
		for(int i=0;i<26;++i)
			val[i] = 0;
	}
	void valueStore(char x) {
		int index = (int)toascii(x)-65;
		if(!val[(int)index]) {
			cout <<"Enter value of " << x ;
			cin >> val[index];
		}
	}
	
	void display() {
		for(int i=0;i<26;++i) {
			cout << val[i] <<endl;
		}
	}

	float retValue(char x) {
		return val[toascii(x)-65];
	}
};

float pow(float x,float y) {
	float res=1;
	for(int i=0;i<y;++i)
		res*=x;
}

int main() {
	MyStack S;
	VariableMap V;
	char p[100];
	float x, y ,res;
	char a, b;//A=56 
  	cout << "Enter the PostFix Expression" << endl;
 	cin >> p;
 	for(int i=0 ; i<strlen(p) ; ++i) {
		if(isalpha(p[i])) {
 			V.valueStore(p[i]);
		}
 	}

	for(int i=0 ; i<strlen(p) ; ++i) {
		if(isalpha(p[i])) {
			cout <<V.retValue(p[i]) <<endl;
		}
	}
	for(int i=0 ; i<strlen(p) ; ++i) {
		if(!(p[i] == '+' ||p[i] == '-' ||p[i] == '*' ||p[i] == '/' ||p[i] == '^'))
			S.push(p[i]);
		else {
			a = S.pop();
			b = S.pop();
			x = V.retValue(a);
			y = V.retValue(b);
			cout << y << p[i] << x <<endl;
			if(p[i] == '+') 
				res = x+y;
			if(p[i] == '-')
				S.push(y-x);
			if(p[i] == '*')
				S.push(y*x);
			if(p[i] == '/')
				S.push(y/x);
			if(p[i] == '^')
				S.push(pow(y,x));
			cout << res <<endl;
			S.push(res);
		}
			
	}
	cout << "Result = " << S.topIs();
	cout << endl;
	
}