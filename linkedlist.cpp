#include <bits/stdc++.h>
using namespace std;
struct Node{
    int info;
    Node* next;
};

//Creating new Node
Node* createNode(int info) {
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Check for allocation failure
    if (newNode == NULL) {
        cout << "Memory allocation failed!\n";
        return nullptr;
    }

    // Assign data to the node
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}
// Printing all node
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}
//Counting and finding total using traversing
void traversing(Node* head){
    Node* temp = head;
    int count = 0, sum = 0;
    while(temp != NULL){
        count++;
        sum += temp->info;
        temp = temp->next;
    }
    cout << "Number of element: " << count << endl;
    cout << "Total = " << sum << endl;
}

//Inserting at tail
void insertAtTail(Node* &head, int val){
    Node*  newNode = createNode(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtHead(Node* &head, int val){
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    cout << "Sucess!" << endl;
}
void insertingAtAnyPos(Node* head, int val, int pos){
    Node*  newNode = createNode(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAnyPos(Node* head, int pos){
    Node* temp = head;
    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
    }
    Node* deleteNode =  temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
Node* deleteHead(Node* head){
    if(head == NULL){
        cout << "Sorry! There is no data to delete!" << endl;
        return NULL;
    }
    Node* nodeToDelete = head; 
    head = head->next;
    delete nodeToDelete;
    cout << "Congrats! Head has been Successfully deleted!" << endl;
    return head;
}
bool searching(Node* head, int val){
    Node* temp = head;
    while(temp != NULL){
        if(temp->info == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main(){
    Node* head = NULL;
    Node* temp;
    int n;
    cout << "Enter the number of input: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(i == 0){
            head = createNode(val);
            temp = head;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }
    print(head);
    // head = deleteHead(head);
    // print(head);
    if(searching(head, 10) == 1){
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }
    insertingAtAnyPos(head, 100, 2);
    print(head);

    return 0;
}