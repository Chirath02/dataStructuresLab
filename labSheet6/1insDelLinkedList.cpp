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
		if(head!=NULL) {
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
			noOfNodes++;
		}
		else 
			cout << "No elements in List " << endl;
		
	}
	
	int count() {
		return noOfNodes;
	}
};
  
  
  int main() {
	  LinkedList L;
	  L.insertAtHead(5);
	  L.display();
 	  L.insertAtEnd(1);
 	  L.display();
  	  L.insertAtK(10,1);
  	  L.display();
  	  L.deleteAtK(1);
  	  L.display();
 	  return 0;
  }