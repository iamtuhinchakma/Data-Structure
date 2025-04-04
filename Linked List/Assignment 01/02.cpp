#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int info) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = info;
    newNode->next = NULL;
    return newNode;
}

// Function to find the index of X in the linked list
int findIndex(Node* head, int x) {
    Node* ptr = head;
    int pos = 0;
    while (ptr != NULL) {
        if (ptr->data == x) {
            return pos;
        }
        ptr = ptr->next;
        pos++;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = NULL, *tail = NULL;
        int val;
        while (true) {
            cin >> val;
            if (val == -1) break;
            
            Node* newNode = createNode(val);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        int x;
        cin >> x;
        cout << findIndex(head, x) << endl;
    }

    return 0;
}
