#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 100

// Stack for evaluation
int stck[MAX], top = -1;
int variableValues[26];  // Array to store values of variables (a-z)
bool isAssigned[26];     // To check if a variable has been assigned a value

// Stack functions
void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stck[++top] = val;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stck[top--];
}

// Evaluate Postfix Expression
int evaluatePostfix(char postfix[]) {
    int len = strlen(postfix);
    
    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (ch == ' ' || ch == ',') continue;  // Ignore spaces and commas

        if (ch >= '0' && ch <= '9') {
            push(ch - '0');  // Convert char digit to integer
        } 
        else if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a'; // Map 'a' to 0, 'b' to 1, ..., 'z' to 25

            // Ask for input only if not assigned before
            if (!isAssigned[index]) {
                cout << "Enter the value of " << ch << ": ";
                cin >> variableValues[index];
                isAssigned[index] = true;
            }
            push(variableValues[index]);
        } 
        else {
            int op2 = pop(); // Second operand
            int op1 = pop(); // First operand

            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
                default: 
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
        }
    }
    return pop(); // Final result
}

int main() {
    char postfix[MAX];
    
    cout << "Enter the postfix expression: ";
    cin >> postfix;

    // Initialize variable assignment tracking (WITHOUT memset)
    for (int i = 0; i < 26; i++) {
        isAssigned[i] = false;
    }

    int result = evaluatePostfix(postfix);
    cout << "Output: " << result << endl;

    return 0;
}
