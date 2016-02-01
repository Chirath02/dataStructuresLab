#include <iostream>
#include <cstring>


using namespace std;

class MyStack {   //Float stack for evaluation
	float arr[200];
	int top, size;
public:
	MyStack() :top(-1), size(200){
	}

	void push(float x) {
		if(top >= size)
			cout << "Stack Overflow" << endl;
		else
			arr[++top] = x;
	}

	float pop() {
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

	float getTop() {
		return arr[top];
	}
};

class VariableMap {   //Class to map variable to values
private:
	float val[26];
	int v;
	float t;
public:
	VariableMap() {
		for(int i=0;i<26;++i)
			val[i] = 0;
	}
	void valueStore(char x, float temp = 0) {
		int index = (int)toascii(x)-65;
		if(!val[(int)index]) {
			if(temp == 0) {
				cout <<"Enter value of " << x ;
				cin >> temp;
			}
			val[index] = temp;
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
 	for(int i=0 ; i<strlen(p) ; ++i) {  //Getting value for each variable
		if(isalpha(p[i])) {
 			V.valueStore(p[i]);
		}
 	}
	for(int i=0 ; i<strlen(p) ; ++i) {
		if(!(p[i] == '+' ||p[i] == '-' ||p[i] == '*' ||p[i] == '/' ||p[i] == '^'))
			S.push(V.retValue(p[i]));
		else {
			x = S.pop();
			y = S.pop();
			if(p[i] == '+')
      	res = x+y;
			if(p[i] == '-')
      	res = x+y;
			if(p[i] == '*')
				res = x+y;
			if(p[i] == '/')
        res = x+y;
			if(p[i] == '^')
				res = x+y;
			S.push(res);
		}

	}
	cout << "Result = " << S.pop();
	cout << endl;

}
