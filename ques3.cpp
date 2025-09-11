#include <iostream>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int isEmpty() {
    return top == -1;
}


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}


void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }
        
        else if (c == '(') {
            push(c);
        }
        
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
        
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
