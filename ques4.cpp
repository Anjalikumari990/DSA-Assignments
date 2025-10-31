#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
    Node(char c) : data(c), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
    Node *head, *tail;
public:
    DoublyLinkedList() { head = tail = NULL; }

    void insert(char c) {
        Node *n = new Node(c);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    bool isPalindrome() {
        if (!head) return true;
        Node *left = head, *right = tail;
        while (left != right && right->next != left) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList list;
    string s;
    cout << "Enter string: ";
    cin >> s;
    for (char c : s) list.insert(c);
    if (list.isPalindrome()) cout << "Palindrome";
    else cout << "Not Palindrome";
    return 0;
}
