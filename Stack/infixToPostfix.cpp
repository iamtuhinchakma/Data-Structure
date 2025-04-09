#include <bits/stdc++.h>
using namespace std;

#define MAX 100
char stck[MAX];
char infix[MAX], postfix[MAX];
int top = -1;
void push(char);
char pop();
int isEmpty();
void inToPost();
void print();
int precedence(char);
int space(char);

void inToPost(){
    char symbol;
    char next;
    int j = 0;
    for(int i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        if(!space(symbol)){
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop()) != '('){
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stck[top]) >= precedence(symbol)){
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
                break;
            }
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int precedence(char symbol){
    switch ((symbol))
    {
    case '^':
        return 3;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
void print(){
    int i = 0;
    while(postfix[i]){
        cout<< postfix[i++];
    }
    cout << endl;
}
void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stck[top] = c;
}
int space(char c){
    if(c == ' ' || c == '\t') return 1;
    else return 0;
}
char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    c = stck[top];
    top = top - 1;
    return c;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int main(){
    // cout << "Enter the infix expression: ";
    gets(infix);

    inToPost();
    print();
    return 0;
}