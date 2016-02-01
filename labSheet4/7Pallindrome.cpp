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
};

class Queue {
	char arr[100], temp;
	int front, rear, len;
public:
	Queue() {
		front = rear = -1;
		len = 100;
	}

	void enQueue(char x) {
		if((rear + 1)%len == front)
			cout << "Queue is full" << endl;
		else {
			if(isEmpty())
				front = rear = 0;
			else
				rear = (rear + 1)%len;
			arr[rear] = x;
		}
	}

	bool isEmpty() {
		if(rear == -1 && front == -1)
			return true;
		return false;
	}

	char Front() {
		return arr[front];
	}

	void display() {
		for(int i=front;i<=rear;++i)
			cout << arr[i];
		cout << endl;
	}

	char deQueue() {
		if (isEmpty())
			cout << "Queue is Empty" << endl;
		else {
			if(rear == front) {
				temp = arr[front];
				front = rear = -1;
			}
			else {
				temp = arr[front];
				front = (front + 1)%len;
			}
			return temp;
		}
	}
};

int main() {
	char temp[100], revStr[100];

	MyStack S;
	Queue Q1, Q2;
	
	cin.getline(temp, 100);
	int i = 0, len = strlen(temp);

	while(i < len)     										//push into Queue1
		Q1.enQueue(temp[i++]);

	cout << "The string is : ";
	Q1.display();

	for(int i=0;i<len;++i)								//push into Stack
		S.push(Q1.deQueue());

	for(int i=0;i<len;++i)								//push inverse string into Queue2
		revStr[i] = S.pop();

	cout << "The reversed string is :" << revStr << endl;

	int flag = 1;													//Check if its a Palindrome
	for(int i=0;i<len;++i)
		if(temp[i] != revStr[i])
			flag = 0;

	if(flag)
			cout << "It is a Palindrome" << endl;
	else
		cout << "It is not a Palindrome" << endl;

	return 0;
}
