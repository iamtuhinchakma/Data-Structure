#include <bits/stdc++.h>
using namespace std;
#define N 100  // Increased stack size

int stck[N];
int top = -1;

void push(int x) {
    if (top == N - 1) {
        cout << "Overflow\n";
    } else {
        stck[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        cout << "Underflow\n";
        exit(1);  // Exit on underflow
    }
    return stck[top--];
}

int peek() {
    if (top == -1) {
        cout << "Underflow\n";
        exit(1);
    }
    return stck[top];
}

void display() {
    for (int i = top; i >= 0; i--) {
        cout << stck[i] << ' ';
    }
    cout << endl;
}

int evaluatePostfix(string exp) {
    for (char c : exp) {
        if (isdigit(c)) {
            push(c - '0');  // Convert char to int
        } else {
            int val1 = peek(); 
            pop(); // First popped is the second operand
            int val2 = peek();  
            pop(); // Second popped is the first operand

            switch (c) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': 
                    if (val1 == 0) {
                        cout << "Error: Division by zero\n";
                        exit(1);
                    }
                    push(val2 / val1);
                    break;
            }
        }
    }
    return peek();  // Final result
}

int main() {
    string exp;
    cout << "Enter a postfix expression: ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
