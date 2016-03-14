#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
};
node*head = NULL;
void reversprint(node*head) {
	if(head==NULL)
		return;
	else {
		reversprint(head->next);
		cout<< head->data<< " ";
	}
}
void insert_at_end(int x) {
	node *temp=new node();
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
		head = temp;
	else {
		node *t2=head;
		while(t2->next!=NULL) {
			t2=t2->next;
		}
		t2->next=temp;
	}
}
void print() {
	node *t2=head;
	cout<<"\n";
	while(t2!=NULL) {
		cout<<t2->data<<" ";
		t2=t2->next;
	}
}

main() {
	insert_at_end(1);
	insert_at_end(2);
	insert_at_end(3);
	insert_at_end(4);
	cout<< endl << "Elements : " ;
	print();
	cout<< endl << "Elements after reversing : " << endl ;
	reversprint(head);
	cout << endl;
}
