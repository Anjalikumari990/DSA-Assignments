#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(char c) { if (!isFull()) arr[++top] = c; }
    char pop() { if (!isEmpty()) return arr[top--]; return '\0'; }
};

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;
    int len = strlen(str);

    Stack st;
    for (int i = 0; i < len; i++) st.push(str[i]);

    cout << "Reversed string: ";
    for (int i = 0; i < len; i++) cout << st.pop();
    cout << endl;

    return 0;
}
