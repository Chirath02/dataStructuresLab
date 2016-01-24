#include <iostream>
#include <cstring>

using namespace std;

class MyStack {
	char arr[200];
	int top, top2, size;
public:
	MyStack() :top(-1), top2(199), size(200){
	}

	void push(char x) {
		if(top >= top2)
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

	void push2(char x) {
		if(top2 <= top)
			cout << "Stack Overflow" << endl;
		else
			arr[--top2] = x;
	}

	char pop2() {
		if(top2 == 200) {
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
	char arr[100], ele;
	int length, top, top2;
	cout << "Enter string" << endl;
	cin >> arr;
	length = strlen(arr);
	for(int i = 0;i < length; i++) {
		S.push(arr[i]);
	}
	char a=arr[0];
	top = S.Top();
	for(int i = 0;i < top; ++i) {
		ele = S.pop();
		if(!(ele > 47 && ele < 58))
			S.push2(ele);
	}
	top2 = S.Top2()+1;
	if(!(a > 47 && a < 58))
        cout << a ;
	for(int i = 200;i > top2; --i)
		cout << S.pop2();
	cout << endl;
}
