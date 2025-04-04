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
//Delete head from the list
Node* deleteHead(Node* &head){
    if(head == NULL){
        return nullptr;
    }
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
    return head;
}
//Delete Tail from the list
Node* deleteTail(Node* &head){
    if(head == NULL){
        return nullptr;
    }
    Node* toDelete;
    if(head->next == NULL){
        toDelete = head;
        delete toDelete;
        return nullptr;
    }
    Node* ptr = head;
    //traverse till the second last node
    //Consider this one: 10 → 20 → 30 → 40 → 50 → NULL
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    toDelete = ptr->next;
    ptr->next = NULL;
    delete toDelete;
    return head;
}
//Delete Node following a given node
Node* deleteAtAnyPos(Node* &head, int pos){
    if(head == NULL) return nullptr;
    Node* ptr = head;
    Node* toDelete;
    for(int i = 1; i < pos - 1; i++)
        ptr = ptr->next;
    
    toDelete = ptr->next;
    ptr->next = ptr->next->next;
    delete toDelete;
    return head;
}
Node* deleteAtAnyIndex(Node* &head, int index) {
    if (head == NULL) return nullptr;
    if (index == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        if (temp == NULL || temp->next == NULL) return nullptr;
        temp = temp->next;
    }
    if (temp->next == NULL) return nullptr;
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}
//Deleting of a node with a given item information
Node* deleteSpecificNode(Node* &head, int item){
    Node* toDelete;
    if(head == NULL)
        return nullptr;
    if(head->data == item){
        toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* ptr = head;
    Node* prevNode = NULL;
    while(ptr != NULL && ptr->data != item){
        prevNode = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL) return head;
    prevNode->next = ptr->next;
    toDelete = ptr;
    delete toDelete;
    return head;
}
int main(){
    // Node* head = createNode(10);
    // Node* second = createNode(20);
    // head->next = second;
    // // cout << first->data << endl;
    // // cout << first->next->data << endl;
    // printLinkedLlist(head);
    
    Node* head = NULL;
    int n;
    cout << "Enter the number of input: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        Node* temp;
        if(i == 0){
            head = createNode(val);
            temp = head;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }
    //printing the list
    printLinkedLlist(head);
    //Deleting head
    // deleteHead(head);
    // cout << "After the deleting of head: ";
    // printLinkedLlist(head);

    // //Deleting from the tail
    // cout << "After the deleting the tail: ";
    // deleteTail(head);
    // printLinkedLlist(head);

    // //Deleting following a given node;
    // cout << "After the deletion of given node: ";
    // deleteAtAnyPos(head, 3);
    // printLinkedLlist(head);

    //Deleting specific information
    cout << "After deleting specific node of given item: ";
    deleteSpecificNode(head, 40);
    printLinkedLlist(head);
    return 0;
}