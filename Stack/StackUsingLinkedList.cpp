#include <bits/stdc++.h>
using namespace std;
struct Node{
    int info;
    Node* next;
    Node* prev;
};
Node* createNode(int val){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->info = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
struct stck{
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    void push(int val){
        size++;
        Node* newNode = createNode(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
    }
    void pop(){
        size--;
        Node* toDelete = tail;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
        } else {
            tail->next = NULL;
        }
    }
    int peek(){
        return tail->info;
    }
    bool empty(){
        if(size == 0){
            return true;
        } else {
            return false;
        }
    }
};
int main(){
    stck stack1;

    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);
    cout << stack1.peek() << endl;
    stack1.pop();
    cout << stack1.peek() << endl;
    // int n;
    // cin >> n;
    // int val;
    // for(int i = 0; i < n; i++){
    //     cin >> val;
    //     stack1.push(val);
    // }

    return 0;
}