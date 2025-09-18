#include <iostream>
using namespace std;

class Queue {
    int arr[20];
    int front, rear, size;
public:
    Queue(int n=20) { front = rear = -1; size = n; }
    bool isEmpty() { return (front == -1); }
    bool isFull() { return (rear == size-1); }
    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }
    int peek() { return isEmpty() ? -1 : arr[front]; }
    int length() { return isEmpty()?0:rear-front+1; }
    void display() {
        for (int i=front; i<=rear; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.length();
    if (n % 2 != 0) { cout << "Queue size must be even\n"; return; }

    Queue firstHalf(n);
    int half = n/2;

    for (int i=0;i<half;i++) firstHalf.enqueue(q.dequeue());

    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue());
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q(20);
    int arr[] = {4,7,11,20,5,9};
    for (int x : arr) q.enqueue(x);

    interleaveQueue(q);
    q.display(); // Output: 4 20 7 5 11 9
}
