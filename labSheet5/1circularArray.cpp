#include <iostream>

using namespace std;

class Cqueue {
	int arr[100], front, rear, len, temp;
public:
	Cqueue() {
		front = rear = -1;
		len = 100;
	}
	
	void insRear(int x) {
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
	
	void insFront(int x) {
		if((rear + 1)%len == front) 
			cout << "Queue is full" << endl;
		else {
			if(isEmpty())
				front = rear = 0;
			else 
				front = (front + len - 1)%len;
			arr[front] = x;
		}
	}
	
	int deleteFront() {
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
	
	int deleteRear() {
		if (isEmpty()) 
			cout << "Queue is Empty" << endl;
		else {
			if(rear == front) {
				temp = arr[front];
				front = rear = -1;
			}
			else {
				rear = (rear + len -1) % len;
			}
			return temp;
		}
	}
	
	
	
	void display() {
		cout << "Queue : " ;
		int i = front;
		while(i!=rear+1) {
			cout << arr[i] << " ";
			i = (i + 1) % len;
		}
		cout << endl;
	}
	
	bool isEmpty() {
		if(rear == -1 && front == -1)
			return true;
		return false;
	}
	
	int Front() {
		return arr[front];
	}
	
	
};

int main() {
	Cqueue Q;
	int choice, ele;
	char ch = 'y';
	while(choice!=7) {
		cout << "Enter 1 for insertion at rear" << endl;
		cout << "Enter 2 for insertion at front " << endl;
		cout << "Enter 3 for deletion  at rear" << endl;
		cout << "Enter 4 for deletion at front" << endl;
		cout << "Enter 5 for display " << endl;
		cout << "Enter 6 for position of front " << endl;
		cout << "Enter 7 to exit " << endl;
		cin >> choice;
		switch(choice) {
			case 1: while(ch=='y'||ch=='Y') {
						cout << "Enter an element to insert at rear :";
						cin >> ele;
						Q.insRear(ele);
						Q.display();
						cout << "Do you wanna enter more ? (Y/N) : ";
						cin >> ch;
					}
					ch='y';
					break;
					
			case 2: while(ch=='y'||ch=='Y') {
					cout << "Enter an element to insert at front :";
					cin >> ele;
					Q.insFront(ele);
					Q.display();
					cout << "Do you wanna enter more ? (Y/N) : ";
					cin >> ch;
				}
				ch='y';
				break;
			
			case 3:while(ch=='y'||ch=='Y') {
					ele = Q.deleteRear();
					cout << "Element deleted is : " << ele << endl;
					Q.display();
					cout << "Do you wanna delete more ? (Y/N) : ";
					cin >> ch;
				}
				ch='y';
				break;
			
			
			case 4:while(ch=='y'||ch=='Y') {
						ele = Q.deleteFront();
						cout << "Element deleted is : " << ele << endl;
						Q.display();
						cout << "Do you wanna delete more ? (Y/N) : ";
						cin >> ch;
					}
					ch='y';
					break;
					
			case 5:Q.display();
				   break;
				  
			case 6:cout << "Front at : " << Q.Front() + 1 << endl;
				   break;
		}
	}
}