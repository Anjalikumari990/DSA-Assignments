#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

int main() {
    Node *head = NULL, *tail = NULL;
    int arr[] = {20, 100, 40, 80, 60};
    for (int x : arr) {
        Node *n = new Node(x);
        if (!head) { head = tail = n; }
        else { tail->next = n; tail = n; }
    }
    tail->next = head;
    Node *temp = head;
    do { cout << temp->data << " "; temp = temp->next; } while (temp != head);
    cout << head->data << endl;
}
