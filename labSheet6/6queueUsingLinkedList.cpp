#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class LinkedList {
	
	Node *newNode, *temp, *temp2, *head;
	int noOfNodes;
	
public:
	
	LinkedList() {
		head = NULL;
		noOfNodes = 0;
	}
	
	void display() {
		temp = head;
		while(temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next; 
		}
		cout << endl;
	}
	
	void insertAtHead(int val) {
		newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		head = newNode;
		noOfNodes++;
	}
	
	void insertAtEnd(int val) {
		newNode = new Node;
		newNode->data = val;
		newNode->next = NULL;
		if(head == NULL) 
			head = newNode;
		else {
			temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
		noOfNodes++;
	}
	
	void insertAtK(int val, int k) {
		newNode = new Node;
		newNode->data = val;
		temp = head;
		for(int i=0; i<k-1 ;++i)
			temp = temp->next;
		newNode->next = temp->next;
		temp->next = newNode;
		noOfNodes++;
	}
	
	int deleteAtK(int k) {
		int ele;
		if(head!=NULL) {
			temp = head;
			if(k==1) {
				temp2 = head;
				ele = temp->data;
				head = temp->next;
			}
			else {
				for(int i=1;i<k-1;++i)
					temp = temp->next;
				temp2 = temp->next;
				ele = temp2->data;
				temp->next = temp2->next;
			}
			delete temp2;
			noOfNodes++;
		}
		else 
			cout << "No elements in List " << endl;
		return ele;
	}
	
	int count() {
		return noOfNodes;
	}
	
	Node *getHead() {
		return head;
	}
};

LinkedList l;

void enqueue(int val) {
	l.insertAtEnd(val);
}

int dequeue() {
	return l.deleteAtK(1);
}

void display() {
	cout << "Queue = " ;
	l.display();
}

int main() {
	cout << "Elements : ";
	for(int i=1; i < 11;++i) {
		cout << i << " ";
		enqueue(i);
	}
	cout << "are enqueued." << endl;
	display();
	for(int i=1; i < 5;++i) {
		cout << "dequeued ele = " << dequeue() << endl; 
	}
	display();
	return 0;
}