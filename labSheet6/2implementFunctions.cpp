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
	
	void deleteAtK(int k) {
		if(temp!=NULL) {
			temp = head;
			if(k==1) {
				temp2 = head;
				head = temp->next;
			}
			else {
				for(int i=1;i<k-1;++i)
					temp = temp->next;
				temp2 = temp->next;
				temp->next = temp2->next;
			}
			delete temp2;
			noOfNodes--;
		}
		else 
			cout << "No elements in List " << endl;
			
	}
	
	int count() {
		return noOfNodes;
	}
	
	void sumOfElements() {
		float sum = 0;
		temp = head;
		while(temp->next != NULL) {
			sum += temp->data;
			temp = temp->next; 
		}
		if(temp->next==NULL)
			sum += temp->data;
		cout << "Sum of Nodes = " << sum << endl;
	}
	
	void chnageValAtK(int val, int k) {
		temp = head;
		for(int i=0; i<k-1 ;++i)
			temp = temp->next;
		temp->data = val;
		display();
	}
	
	void largestToEnd() {
		temp = head;
		int large = temp->data, pos=1 , i=0, val;
		if(head != NULL) {
			do {
				i++;
				if(temp->data >= large) {
					large = temp->data;
					pos = i;
				}
				temp = temp->next; 
			}while(temp!=NULL);
		
			if(pos != count()) {
				deleteAtK(pos);
				insertAtK(large,i);
			}
			cout << "Largest moved to end " << endl;
			display();
		}
		else
			cout << "No elements in List " << endl;
	}
	
	void searchELe(int ele) {
		temp = head;
		int pos=0 , i=0, val;
		if(head != NULL) {
			do {
				i++;
				if(temp->data == ele) 
					pos = i;
				temp = temp->next; 
			}while(temp->next!=NULL);
			if(temp->next==NULL)
				if(temp->data == ele) 
					pos = i+1;
			if(pos != 0)
				cout << ele << " fount at index = " << pos << endl;
			else 
				cout << "Element not found !" << endl;
		}
		else
			cout << "No elements in List " << endl;
	}
	
	void deleteEven() {
		temp = head;
		int  i=1, val;
		if(head != NULL) {
			do {
				if(temp->data % 2 == 0)
 					deleteAtK(i);
				else
					i++;
				temp = temp->next; 
			}while(temp!=NULL);
			cout << "Deleted even elements " << endl;
			display();
		}
		else
			cout << "No elements in List " << endl;		
	}
	
	Node* getHead() {
		return head;
	}
	
	void concat2(LinkedList L2) {
		temp = head;
 		while(temp->next != NULL)
 			temp = temp->next;
		temp->next = L2.getHead();
		
		cout << "Linked list after concatation = ";
		display();
	
	}
  };
  

int main() {
	LinkedList L, L2;
	L.insertAtHead(100);
	L.insertAtHead(50);
	L.insertAtEnd(71);
	L.insertAtK(10,1);
	L.display();
	cout << "Number of Nodes = " << L.count() << endl;
	L.sumOfElements();
 	L.chnageValAtK(99,2);
 	L.largestToEnd();
 	L.searchELe(50);
 	L.deleteEven();
	cout << "Linked list 1 = ";
	L.display();
	L2.insertAtEnd(1);
	L2.insertAtEnd(2);
	L2.insertAtEnd(2);
	cout << "Linked list 2 = ";
	L2.display();
	L.concat2(L2);
	return 0;
}