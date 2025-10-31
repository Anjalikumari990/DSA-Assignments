#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *next, *prev;
    DNode(int val):data(val),next(NULL),prev(NULL){}
};

struct CNode {
    int data;
    CNode *next;
    CNode(int val):data(val),next(NULL){}
};

int sizeDoubly(DNode *head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

int sizeCircular(CNode *head) {
    if (!head) return 0;
    int count = 0;
    CNode *temp = head;
    do { count++; temp = temp->next; } while (temp != head);
    return count;
}

int main() {
    DNode *d1 = new DNode(10);
    d1->next = new DNode(20);
    d1->next->prev = d1;
    d1->next->next = new DNode(30);
    cout << "Size of Doubly Linked List = " << sizeDoubly(d1) << endl;

    CNode *c1 = new CNode(5);
    c1->next = new CNode(15);
    c1->next->next = new CNode(25);
    c1->next->next->next = c1;
    cout << "Size of Circular Linked List = " << sizeCircular(c1) << endl;
}
