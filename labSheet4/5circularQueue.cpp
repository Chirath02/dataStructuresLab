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
		for(int i=front;i<=rear;++i)
			cout << arr[i] << " ";
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

int main() {
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
	
	Q.deQueue();
	Q.deQueue();
	
	Q.display();
}