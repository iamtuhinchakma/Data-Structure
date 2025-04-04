#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createNode(int info){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = info;
    newNode->next = NULL;
    return newNode;
}
//Traversing the linked list
void printLinkedLlist(Node* start){
    Node* ptr = start;
    while(ptr != NULL){
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}
Node* insertAtTail(Node* &head, int val){
    Node* newNode = createNode(val);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return newNode;
}

int main(){
    int value;
    Node *head = NULL, *tail = NULL;
    int minV = 1000000000, maxV = -1000000000;

    // Read values until -1 is encountered
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;

        // Update min and max values
        if (value < minV) minV = value;
        if (value > maxV) maxV = value;

        // Create a new node and add it to the list
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("%d\n", maxV - minV);
    return 0;
}