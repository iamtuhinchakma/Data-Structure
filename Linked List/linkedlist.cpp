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

//Printing using recursion
void printRecursively(Node* head){
    if(head == NULL) return;
    cout << head->data << ' ';
    printRecursively(head->next);
}
//Print in reverse
void printInReverse(Node* head){
    if(head == NULL) return;
    printInReverse(head->next);
    cout << head->data << ' ';
}
//Searching in unsorted List
bool searching(Node* start, int item){
    Node* ptr = start;
    while(ptr != NULL){
        if(ptr->data == item){
            return true;
        } else {
            ptr = ptr->next;
        }
    }
    return false;
}
//Seaching in the sorted list
// bool searchingInSortedList(Node* start, int item){
//     Node* ptr = start;
//     while(ptr != NULL){
//         if(item == ptr->data){
//             return true;
//         } else if(item < ptr->data){
//             return false;
//         }
//         ptr = ptr->next;
//     }
//     return false;
// }
bool searchingInSortedList(Node* start, int item){
    Node* ptr = start;
    while(ptr != NULL){
        if(item > ptr->data){
            ptr = ptr->next;
        } else if(ptr->data == item){
            return true;
        } else {
            return false;
        }
    }
    return false;
}
//Insertion at Head
Node* insertAtHead(Node* &head, int item){
    Node* newNode = createNode(item);
    newNode->next = head;
    head = newNode;
    cout << "Successfully Inserted!\n";
    return newNode;
}

//Inserting at following a given node
Node* insertAtAnyPos(Node* &head, int item, int pos){
    Node* newNode = createNode(item);
    if(pos < 1){
        return head;
    }
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return newNode;
    }
    Node* ptr = head;
    for(int i = 1; i < pos - 1; i++)
        ptr = ptr->next;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return newNode;
    
}
//Inserting at Tail
Node* insertAtTail(Node* &head, int item){
    Node* newNode = createNode(item);
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
//Inserting into a sorted list
Node* insertIntoSortedList(Node* &head, int item){
    Node* newNode = createNode(item);
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->data < item){
            ptr = ptr->next;
        } else {
            break;
        }
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
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

    //Searching in the list
    if(searching(head, 30) == 1)
        cout << "Item has been found" << endl;
    else 
        cout << "Item not found" << endl;
    
    
    //Searching in the sorted list
    if(searchingInSortedList(head, 25) == 1)
        cout << "Item has been found" << endl;
    else 
        cout << "Item not found" << endl;
    

    //Inserting at head
    insertAtHead(head, 1021);
    cout << "After insertion at head: ";
    printLinkedLlist(head);

    //Inserting following a given node;
    insertAtAnyPos(head, 700, 3);
    cout << "After inserting at any pos: ";
    printLinkedLlist(head);

    //Inserting at Tail
    insertAtTail(head, 900);
    cout << "After inserting at tail: ";
    printLinkedLlist(head);

    //Inserting to a sorted list
    insertIntoSortedList(head, 35);
    cout << "After inserting into a sorted List: ";
    printLinkedLlist(head);

    //Printing using recursion
    cout << "Printed using recursion: ";
    printRecursively(head);
    cout << endl;

    //Print in reverse
    cout << "Reverse Print: ";
    printInReverse(head);
    return 0;
}