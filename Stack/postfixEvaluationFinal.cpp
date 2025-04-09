#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int stck[MAX];
int top = -1;

void push(int);
int pop();
int isEmpty();
int evaluatePostfix(char*);

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stck[++top] = val;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return stck[top--];
}

int isEmpty() {
    return top == -1;
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    while (postfix[i]) {
        // Skip spaces, tabs, and commas
        if (postfix[i] == ' ' || postfix[i] == '\t' || postfix[i] == ',') {
            i++;
            continue;
        }

        // If the character is a digit, extract the full number
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
            continue;
        }

        // If the character is an operator, process it
        int op2 = pop(); // Second operand
        int op1 = pop(); // First operand
        switch (postfix[i]) {
            case '+': push(op1 + op2); break;
            case '-': push(op1 - op2); break;
            case '*': push(op1 * op2); break;
            case '/': push(op1 / op2); break;
            case '^': push(pow(op1, op2)); break;
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX];
    cout << "Enter the postfix expression: ";
    cin.getline(postfix, MAX);
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
