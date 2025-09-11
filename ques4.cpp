#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};


int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


bool isOperand(char c) {
    return ( (c >= 'A' && c <= 'Z') ||
             (c >= 'a' && c <= 'z') ||
             (c >= '0' && c <= '9') );
}


void infixToPostfix(char exp[]) {
    Stack s;
    char postfix[MAX];
    int i = 0, k = 0;

    while (exp[i] != '\0') {
        char c = exp[i];

        
        if (isOperand(c)) {
            postfix[k++] = c;
        }
        
        else if (c == '(') {
            s.push(c);
        }
        
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            s.pop(); 
        }
        
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix[k++] = s.pop();
            }
            s.push(c);
        }
        i++;
    }


    while (!s.isEmpty()) {
        postfix[k++] = s.pop();
    }

    postfix[k] = '\0';
    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    char expression[MAX];
    cout << "Enter Infix Expression: ";
    cin >> expression;  

    infixToPostfix(expression);

    return 0;
}
