#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int val) : data(val), prev(NULL), next(NULL) {}
};

struct CNode {
    int data;
    CNode *next;
    CNode(int val) : data(val), next(NULL) {}
};

class DoublyLinkedList {
    DNode *head;
public:
    DoublyLinkedList() { head = NULL; }
    void insertFirst(int val) {
        DNode *n = new DNode(val);
        if (!head) head = n;
        else { n->next = head; head->prev = n; head = n; }
    }
    void insertLast(int val) {
        DNode *n = new DNode(val);
        if (!head) head = n;
        else { DNode *t = head; while (t->next) t = t->next; t->next = n; n->prev = t; }
    }
    void insertAfter(int key, int val) {
        DNode *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) { cout << "Not found\n"; return; }
        DNode *n = new DNode(val);
        n->next = t->next; n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertFirst(val); return; }
        DNode *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) { cout << "Not found\n"; return; }
        DNode *n = new DNode(val);
        n->next = t; n->prev = t->prev;
        t->prev->next = n; t->prev = n;
    }
    void deleteNode(int key) {
        DNode *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) { cout << "Not found\n"; return; }
        if (t->prev) t->prev->next = t->next; else head = t->next;
        if (t->next) t->next->prev = t->prev;
        delete t; cout << "Deleted\n";
    }
    void search(int key) {
        DNode *t = head;
        while (t && t->data != key) t = t->next;
        if (t) cout << "Found\n"; else cout << "Not found\n";
    }
    void display() {
        DNode *t = head; while (t) { cout << t->data << " "; t = t->next; } cout << endl;
    }
};

class CircularLinkedList {
    CNode *head;
public:
    CircularLinkedList() { head = NULL; }
    void insertFirst(int val) {
        CNode *n = new CNode(val);
        if (!head) { head = n; n->next = n; }
        else { CNode *t = head; while (t->next != head) t = t->next; n->next = head; t->next = n; head = n; }
    }
    void insertLast(int val) {
        CNode *n = new CNode(val);
        if (!head) { head = n; n->next = n; }
        else { CNode *t = head; while (t->next != head) t = t->next; t->next = n; n->next = head; }
    }
    void insertAfter(int key, int val) {
        if (!head) return;
        CNode *t = head;
        do {
            if (t->data == key) {
                CNode *n = new CNode(val);
                n->next = t->next; t->next = n; return;
            }
            t = t->next;
        } while (t != head);
        cout << "Not found\n";
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        CNode *cur = head, *prev = NULL;
        do {
            if (cur->data == key) {
                CNode *n = new CNode(val);
                n->next = cur;
                if (prev) prev->next = n;
                else { CNode *last = head; while (last->next != head) last = last->next; last->next = n; head = n; }
                return;
            }
            prev = cur; cur = cur->next;
        } while (cur != head);
        cout << "Not found\n";
    }
    void deleteNode(int key) {
        if (!head) return;
        CNode *cur = head, *prev = NULL;
        do {
            if (cur->data == key) {
                if (cur == head && cur->next == head) { head = NULL; }
                else if (cur == head) {
                    CNode *last = head; while (last->next != head) last = last->next;
                    head = head->next; last->next = head;
                } else prev->next = cur->next;
                delete cur; cout << "Deleted\n"; return;
            }
            prev = cur; cur = cur->next;
        } while (cur != head);
        cout << "Not found\n";
    }
    void search(int key) {
        if (!head) return;
        CNode *t = head;
        do { if (t->data == key) { cout << "Found\n"; return; } t = t->next; } while (t != head);
        cout << "Not found\n";
    }
    void display() {
        if (!head) return;
        CNode *t = head;
        do { cout << t->data << " "; t = t->next; } while (t != head);
        cout << head->data << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int type, ch, val, key;
    while (true) {
        cout << "\n1.Doubly List 2.Circular List 3.Exit: "; cin >> type;
        if (type == 3) break;
        cout << "1.Insert First 2.Insert Last 3.Insert After 4.Insert Before 5.Delete 6.Search 7.Display 8.Back\n";
        while (true) {
            cout << "Enter choice: "; cin >> ch;
            if (ch == 8) break;
            switch (ch) {
                case 1: cout << "Value: "; cin >> val; (type==1)?dll.insertFirst(val):cll.insertFirst(val); break;
                case 2: cout << "Value: "; cin >> val; (type==1)?dll.insertLast(val):cll.insertLast(val); break;
                case 3: cout << "After which? "; cin >> key; cout << "Value: "; cin >> val; (type==1)?dll.insertAfter(key,val):cll.insertAfter(key,val); break;
                case 4: cout << "Before which? "; cin >> key; cout << "Value: "; cin >> val; (type==1)?dll.insertBefore(key,val):cll.insertBefore(key,val); break;
                case 5: cout << "Delete value: "; cin >> key; (type==1)?dll.deleteNode(key):cll.deleteNode(key); break;
                case 6: cout << "Search value: "; cin >> key; (type==1)?dll.search(key):cll.search(key); break;
                case 7: (type==1)?dll.display():cll.display(); break;
            }
        }
    }
}
