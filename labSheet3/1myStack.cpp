#include <iostream>

using namespace std;

class MyStack {
	int arr[200];
	int top, size;
public:
	MyStack() :top(-1), size(200){
	}
	
	void push(int x) {
		if(top >= size)
			cout << "Stack Overflow" << endl;
		else
			arr[++top] = x;
	}
	
	int pop() {
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
	printISEmpty(S.isEmpty());
	S.push(1);
	S.push(5);
	S.push(10);
	cout << "Top = " << S.topIs() << endl;
	printISEmpty(S.isEmpty());
 	cout << "Element poped = " << S.pop() << endl;
	cout << "Top = " << S.topIs() << endl;
	cout << "Minimum element = " << S.getMin() << endl;
	cout << "Element poped = " << S.pop() << endl;
	return 0;
}