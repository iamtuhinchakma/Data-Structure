#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int rear = -1, front = -1;
int queueArr[MAX];
void insert(){
    int num;
    if(rear == MAX - 1){
        cout << "Queue is Full\n";
        return;
    }
    cout << "Enter a number to insert: ";
    cin >> num;
    if(front == -1)
        front++;
    rear++;
    queueArr[rear] = num;
}
void delet(){
    int numToDelete;
    if(front == -1 || rear == -1){
        cout << "Queue is empty\n";
        return;
    }
    numToDelete = queueArr[front];
    front++;
}
void display(){
    if(front == -1 || rear == -1){
        cout << "Queue is Empty\n";
        return;
    }
    for(int i = front; i <= rear; i++){
        cout << queueArr[i] << ' ';
    }
    cout << endl;
}
int main(){
    display();
    insert();
    insert();
    insert();
    display();
    insert();
    insert();
    display();
    delet();
    delet();
    display();
}