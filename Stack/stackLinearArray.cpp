#include <bits/stdc++.h>
using namespace std;
#define N 5
int stck[N];
int top = -1;
void push(int x){
    if(top == N - 1){
        cout << "Overflow\n";
    } else {
        top++;
        stck[top] = x;
    }
}
void pop(){
    if(top == -1){
        cout << "Underflow\n";
    } else {
        top--;
    }
}
int peek(){
    if(top == -1){
        cout << "Underflow\n";
    } else {
        return stck[top];
    }
}
void display(){
    for(int i = top; i >= 0; i--){
        cout << stck[i] << ' ';
    }
    cout << endl;
}
int main(){
    // push(40);
    // push(50);
    // push(60);
    // push(70);
    int n;
    cin >> n;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        push(val);
    }
    display();
    cout << peek() << endl;
    pop();
    display();
}