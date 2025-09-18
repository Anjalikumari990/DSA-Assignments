#include <iostream>
using namespace std;

class Queue {
    int arr[50];
    int front, rear, size;
public:
    Queue(int n=50) { front=rear=-1; size=n; }
    bool isEmpty() { return front==-1; }
    void enqueue(int x) {
        if (rear==size-1) return;
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
    int peek() { return isEmpty()?-1:arr[front]; }
};

class Stack {
    Queue q;
public:
    void push(int x) {
        q.enqueue(x);
        int sz = q.length();
        while (sz > 1) {
            q.enqueue(q.dequeue());
            sz--;
        }
    }
    void pop() {
        if (q.isEmpty()) { cout<<"Stack Empty\n"; return; }
        cout<<q.dequeue()<<" popped\n";
    }
    void top() {
        if (q.isEmpty()) cout<<"Stack Empty\n";
        else cout<<"Top = "<<q.peek()<<endl;
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(15);
    st.top();
    st.pop();
    st.top();
}
