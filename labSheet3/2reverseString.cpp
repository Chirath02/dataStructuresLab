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
	
	int getMin() {
		int min = arr[0];
		for(int i = 1;i < top; ++i)
			if(arr[i] < min)
				min = arr[i];
		return min;
	}
};

void printISEmpty(bool b) {
	if(b)
		cout << "Stack is Empty" << endl;
	else
		cout << "Stack is not Empty" << endl;
}

int main() {
	MyStack S;
	char arr[100], length;
	cout << "Enter string" << endl;
		cin >> arr;
	length = strlen(arr);
	for(int i = 0;i < length; ++i)
		S.push(arr[i]);
	for(int i = 0;i < length; ++i)
		arr[i] = S.pop();
	cout << "Reversed string is ";
	cout << arr << endl;
}