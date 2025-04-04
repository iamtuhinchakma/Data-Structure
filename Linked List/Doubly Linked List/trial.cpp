#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* createNode(int info){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = info;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}
void reversePrint(Node* tail){
    Node* ptr = tail;
    while(ptr != NULL){
        cout << ptr->data << ' ';
        ptr = ptr->prev;
    }
    cout << endl;
}
//Inserting at any position
Node* insertAtAnyIndex(Node* &head, int info, int pos){
    Node* newNode = createNode(info);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node* ptr = head;
    for(int i = 0; i < pos - 1; i++)
        ptr = ptr->next;
    
    newNode->next = ptr->next;
    ptr->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = ptr;
    return head;
}
//Inserting at head;
Node* insertAtHead(Node* &head, Node* &tail, int info){
    Node* newNode = createNode(info);
    if(head == NULL){
        head = tail = newNode;
        return head;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}
//Inserting at tail
Node* insertAtTail(Node* &tail, int info){
    Node* newNode = createNode(info);
    Node* ptr = tail;
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
    return tail;
}
Node* deleteAtAnyPos(Node* &head, int pos){
    Node* ptr = head;
    for(int i = 0; i < pos - 1; i++)
        ptr = ptr->next;
    
    Node* toDelete = ptr->next;
    ptr->next = ptr->next->next;
    ptr->next->prev = ptr;
    delete toDelete;
    return head;
}
int main(){
    Node* head = createNode(10);
    Node* a = createNode(20);
    Node* b = createNode(30);
    Node* c = createNode(40);
    Node* tail = c;
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    printList(head);
    reversePrint(tail);

    insertAtAnyIndex(head, 100, 3);
    cout << "After inserting a value: ";
    printList(head);

    insertAtHead(head, tail, 300);
    cout << "After inserting at head: ";
    printList(head);

    insertAtTail(tail, 15);
    cout << "After inserting at tail: ";
    printList(head);

    deleteAtAnyPos(head, 7);
    cout << "Items after deleting a node: ";
    printList(head);
    return 0;
}