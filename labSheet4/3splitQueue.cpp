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

void splitQueue(Queue Q, Queue *Q1, Queue *Q2) {
	while(!Q.isEmpty()) {
		Q1->enQueue(Q.deQueue());
		Q2->enQueue(Q.deQueue());
	}
}

int main() {
	Queue Q,Q1,Q2;
	Q.enQueue(5);
	Q.enQueue(6);
	Q.enQueue(1);
	Q.enQueue(2);
	Q.enQueue(3);
	Q.enQueue(4);
	Q.enQueue(7);
	Q.enQueue(9);
	splitQueue(Q, &Q1, &Q2);
	cout << "Queue 1 contains : ";
	while(!Q.isEmpty())
		cout << Q.deQueue() << " ";
	cout << endl;
	cout << "After spliting : " << endl;
	cout << "Queue 2 contains : ";
	while(!Q1.isEmpty())
		cout << Q1.deQueue() << " ";
	cout << endl;
	cout << "Queue 3 contains : ";
	while(!Q2.isEmpty())
		cout << Q2.deQueue() << " ";
	cout << endl;
}