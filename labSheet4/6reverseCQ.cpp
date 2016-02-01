#include <iostream>

using namespace std;

class Queue {
	int arr[100], front, rear, len, temp;
public:
	Queue() {
		front = rear = -1;
		len = 100;
	}

	void enQueue(int x) {
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

	int Front() {
		return arr[front];
	}

	void display() {
		int i=front;
		while(i!=rear) {
			cout << arr[i++] << " ";
			if(i==len-1)
				i=0;
			}
		cout << endl;
	}

	int deQueue() {
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


int main() {
	MyStack S;
	Queue Q;
	Q.enQueue(5);
	Q.enQueue(6);
	Q.enQueue(1);
	Q.enQueue(2);
	Q.enQueue(3);
	Q.enQueue(4);
	Q.enQueue(7);
	Q.enQueue(9);

 	Q.display();

 	while(!Q.isEmpty())
 		S.push(Q.deQueue());

	while(!S.isEmpty())
		Q.enQueue(S.pop());

	Q.display();
}
