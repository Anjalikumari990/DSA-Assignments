#include <iostream>
using namespace std;

class Queue {
    int arr[50];
    int front, rear, size;
public:
    Queue(int n=50) { front = rear = -1; size = n; }
    bool isEmpty() { return front==-1; }
    void enqueue(int x) {
        if (rear == size-1) return;
        if (front==-1) front=0;
        arr[++rear]=x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int x=arr[front];
        if (front==rear) front=rear=-1;
        else front++;
        return x;
    }
    int length() { return isEmpty()?0:rear-front+1; }
};

class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) q2.enqueue(q1.dequeue());
        swap(q1,q2);
    }
    void pop() {
        if (q1.isEmpty()) { cout<<"Stack Empty\n"; return; }
        cout<<q1.dequeue()<<" popped\n";
    }
    void top() {
        if (q1.isEmpty()) cout<<"Stack Empty\n";
        else cout<<"Top = "<<q1.dequeue()<<endl; // careful: removes
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.pop();
    st.pop();
    st.pop();
}
