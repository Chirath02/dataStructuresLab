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

class Queue {
	MyStack S1, S2;
	int front, rear, len, temp;
public:
	Queue() {
		front = rear = -1;
		len = 100;
	}
	
	void enQueue(int x) {
		if(rear == len-1) 
			cout << "Queue is full" << endl;
		else {
			if(isEmpty())
				front = rear = 0;
			else 
				rear++;
			S1.push(x);
		}
	}
	
	bool isEmpty() {
		if(rear == -1 && front == -1)
			return true;
		return false;
	}
	
	int pop() {
		while(!S1.isEmpty()) 
			S2.push(S1.pop());
		temp = S2.pop();
		while(!S2.isEmpty()) 
			S1.push(S2.pop());
		return temp;
	}
	
	int deQueue() {
		if (isEmpty()) 
			cout << "Queue is Empty" << endl;
		else {
			if(rear == front) {
				temp = pop();
				front = rear = -1;
			}
			else {
				temp = pop();
				front++;
			}
			return temp;
		}
	}
};



int main() {
	Queue Q;
	Q.enQueue(5);
	Q.enQueue(6);
	Q.enQueue(7);
	cout << Q.deQueue() << endl;
	cout << Q.deQueue() << endl;
	cout << Q.deQueue() << endl;
}
