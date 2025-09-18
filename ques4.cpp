#include <iostream>
using namespace std;

class Queue {
    char arr[100];
    int front, rear;
public:
    Queue() { front = rear = -1; }
    bool isEmpty() { return (front == -1); }
    void enqueue(char x) {
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else front++;
    }
    char peek() { return isEmpty() ? '#' : arr[front]; }
};

void firstNonRepeating(string s) {
    int freq[256] = {0};
    Queue q;

    for (char ch : s) {
        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.peek()] > 1) q.dequeue();

        if (q.isEmpty()) cout << "-1 ";
        else cout << q.peek() << " ";
    }
    cout << endl;
}

int main() {
    string s = "aabc";
    firstNonRepeating(s); // Output: a -1 b b
}
