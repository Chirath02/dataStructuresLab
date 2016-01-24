#include <iostream>

using namespace std;

class MyStack {
	int arr[200];
	int top, top2, size;
public:
	MyStack() :top(-1), top2(201), size(200){
	}

	void push(int x) {
		if(top >= top2)
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

	void push2(int x) {
		if(top2 <= top)
			cout << "Stack Overflow" << endl;
		else
			arr[--top2] = x;
	}

	int pop2() {
		if(top2 == 201) {
			cout << "Stack Underflow" << endl;
		}
		else
			return arr[top2++];
	}

	int Top() {
		return top;
	}

	int Top2() {
		return top2;
	}
};

int main() {
	MyStack S;

	S.push(2);
	S.push(3);
	S.push(4);
	cout << "Top = " << S.Top2() << endl;
	cout << "Top2 = " << S.Top2() << endl;
 	cout << "Element poped = " << S.pop() << endl;
	cout << "Element poped = " << S.pop() << endl;
	cout << "Element poped = " << S.pop() << endl;
	cout << "Top = " << S.Top() << endl;
	cout << "Top2 = " << S.Top2() << endl;
	return 0;
}
