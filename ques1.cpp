#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = createNode(val);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertBeforeValue(int val, int target) {
    Node* newNode = createNode(val);
    if (!head) return;
    if (head->data == target) { newNode->next = head; head = newNode; return; }
    Node* temp = head;
    while (temp->next && temp->next->data != target) temp = temp->next;
    if (temp->next) { newNode->next = temp->next; temp->next = newNode; }
}

void insertAfterValue(int val, int target) {
    Node* temp = head;
    while (temp && temp->data != target) temp = temp->next;
    if (temp) { Node* newNode = createNode(val); newNode->next = temp->next; temp->next = newNode; }
}

void deleteFromBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = NULL; return; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int val) {
    if (!head) return;
    if (head->data == val) { Node* temp = head; head = head->next; delete temp; return; }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (temp->next) { Node* del = temp->next; temp->next = temp->next->next; delete del; }
}

void searchNode(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == val) { cout << "Node " << val << " found at position " << pos << endl; return; }
        temp = temp->next; pos++;
    }
    cout << "Node not found\n";
}

void displayList() {
    Node* temp = head;
    while (temp) { cout << temp->data << " -> "; temp = temp->next; }
    cout << "NULL\n";
}

int main() {
    int choice, val, target;
    while (true) {
        cout << "\nMenu:\n1.Insert at beginning\n2.Insert at end\n3.Insert before value\n4.Insert after value\n5.Delete from beginning\n6.Delete from end\n7.Delete specific\n8.Search node\n9.Display list\n10.Exit\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: cin >> val; insertAtBeginning(val); break;
            case 2: cin >> val; insertAtEnd(val); break;
            case 3: cin >> val >> target; insertBeforeValue(val,target); break;
            case 4: cin >> val >> target; insertAfterValue(val,target); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: cin >> val; deleteSpecific(val); break;
            case 8: cin >> val; searchNode(val); break;
            case 9: displayList(); break;
            case 10: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
