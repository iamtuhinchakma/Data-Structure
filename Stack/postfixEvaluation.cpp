#include <bits/stdc++.h>
using namespace std;

#define MAX 100
char infix[MAX], postfix[MAX]; // Infix and postfix expressions
int stck[MAX], top = -1;       // Stack for postfix evaluation

// Stack functions
void push(char);
char pop();
int isEmpty();
int precedence(char);
int space(char);

// Convert infix to postfix
void inToPost() {
    char symbol, next;
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (!isEmpty() && precedence(stck[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol; // Operand directly to output
                    break;
            }
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// Operator precedence function
int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Ignore spaces and tabs
int space(char c) {
    return (c == ' ' || c == '\t');
}

// Stack functions
void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stck[++top] = c;
}

char pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stck[top--];
}

int isEmpty() {
    return top == -1;
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    int numStack[MAX], numTop = -1;
    
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            numStack[++numTop] = ch - '0'; // Convert char to int and push
        } else {
            int op2 = numStack[numTop--]; // Second operand
            int op1 = numStack[numTop--]; // First operand

            switch (ch) {
                case '+': numStack[++numTop] = op1 + op2; break;
                case '-': numStack[++numTop] = op1 - op2; break;
                case '*': numStack[++numTop] = op1 * op2; break;
                case '/': numStack[++numTop] = op1 / op2; break;
            }
        }
    }
    return numStack[numTop];
}

int main() {
    cout << "Enter an infix expression: ";
    cin.getline(infix, MAX);

    inToPost();
    cout << "Postfix Expression: " << postfix << endl;
    
    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
