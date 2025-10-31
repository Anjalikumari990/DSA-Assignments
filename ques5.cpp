#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

bool isCircular(Node *head) {
    if (!head) return true;
    Node *temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return (temp == head);
}

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head; 

    if (isCircular(head)) cout << "Circular Linked List";
    else cout << "Not Circular Linked List";
    return 0;
}
