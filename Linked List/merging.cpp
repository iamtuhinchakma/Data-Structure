#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int info) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = info;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void PrintLinkedList(Node* head) {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}

// Function to merge two linked lists (appends second list to first)
void mergeLists(Node*& head, Node* head1) {
    if (head == NULL) {
        head = head1;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head1;
}

// Function to sort the linked list using Bubble Sort
void sortList(Node* head){
    for(Node* i = head; i->next != NULL; i = i->next){
        for(Node* j = i->next; j != NULL; j = j->next){
            int temp;
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, m, val;
    cin >> n >> m;

    // Creating first linked list
    for (int i = 0; i < n; i++) {
        cin >> val;
        Node* newNode = createNode(val);
        if (i == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    PrintLinkedList(head);

    // Creating second linked list
    Node* head1 = NULL;
    Node* tail1 = NULL;
    for (int i = 0; i < m; i++) {
        cin >> val;
        Node* newNode = createNode(val);
        if (i == 0) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    PrintLinkedList(head1);

    // Merging second list into first
    mergeLists(head, head1);
    cout << "After merging: ";
    PrintLinkedList(head);

    // Sorting the merged linked list
    sortList(head);
    cout << "After sorting: ";
    PrintLinkedList(head);

    return 0;
}
