#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
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
    while(temp){ cout<<temp->data; if(temp->next) cout<<" -> "; temp=temp->next; }
    cout<<endl;
}

void countAndDelete(int key) {
    int count=0;
    while(head && head->data==key){ Node* temp=head; head=head->next; delete temp; count++; }
    Node* curr=head;
    while(curr && curr->next){
        if(curr->next->data==key){ Node* del=curr->next; curr->next=curr->next->next; delete del; count++; }
        else curr=curr->next;
    }
    cout<<"Count: "<<count<<endl;
}

int main() {
    insertEnd(1); insertEnd(2); insertEnd(1); insertEnd(2); insertEnd(1); insertEnd(3); insertEnd(1);
    display();
    countAndDelete(1);
    display();
}
