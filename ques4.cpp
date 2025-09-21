#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node{val,NULL};
    if(!head){ head=newNode; return; }
    Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next=newNode;
}

void display() {
    Node* temp=head;
    while(temp){ cout<<temp->data<<" -> "; temp=temp->next; }
    cout<<"NULL\n";
}

void reverseList() {
    Node *prev=NULL, *curr=head, *next=NULL;
    while(curr){ next=curr->next; curr->next=prev; prev=curr; curr=next; }
    head=prev;
}

int main() {
    for(int i=1;i<=4;i++) insertEnd(i);
    display();
    reverseList();
    display();
}
