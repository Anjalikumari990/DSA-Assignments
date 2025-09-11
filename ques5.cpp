#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stackArr[top--];
}

int calc(int a, int b, char c){
    switch(c){
        case '+': return a + b; break;
        case '-': return a - b; break;
        case '*': return a * b; break;
        case '/': return a / b; break;
    }
}

int main(){
    char s [100];
    cout << "Enter your postfix function:";
    cin >> s;

    for(int i = 0; s[i] != 0; i++){
        if(isdigit (s[i])){
            s[i] = s[i] - '0';
            push s[i];
        }
        if((s[i] == '*') || (s[i] == '/') || (s[i] == '+') || (s[i] == '-')){

        }
        int a = pop();
        int b = pop();
        c = calc(a, b, s[i]);
        push(s);
    }
    
}