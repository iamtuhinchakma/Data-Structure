#include <iostream>
#include <vector>
using namespace std;

struct Stack {
    vector<int> stack;

    // Check if stack is empty
    bool isEmpty() {
        return stack.empty();
    }

    // Push function
    void push(int value) {
        stack.push_back(value);
        cout << "Pushed " << value << "\n";
    }

    // Pop function
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int topValue = stack.back();
        stack.pop_back();
        return topValue;
    }

    // Peek function
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return stack.back();
    }
};

// Main function to test stack
int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.peek() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    
    if (s.isEmpty()) {
        cout << "Stack is now empty.\n";
    }
    
    return 0;
}
