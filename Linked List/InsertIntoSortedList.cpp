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
//Inserting into a sorted list
Node* insertIntoSortedList(Node* &head, int item){
    Node* newNode = createNode(item);
    if(head == NULL || head->data > item){
        newNode->next = head;
        head =  newNode;
    } else {
        Node* ptr = head;
        while(ptr->next != NULL && ptr->next->data < item){
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return newNode;
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
    //Inserting to a sorted list
    insertIntoSortedList(head, 35);
    cout << "After inserting into a sorted List: ";
    printLinkedLlist(head);
    return 0;
}