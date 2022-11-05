#include "bits/stdc++.h"

using namespace std;

typedef struct stack {
    int data;
    struct stack *next;
} Stack;

Stack * top = NULL;

void push(int value) {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->data = value;
    s->next = top;
    top = s;
}

int isEmpty(){
    return top == NULL;
}

int pop() {
    if(isEmpty()){
        return NULL;
    }
    int data = top->data;
    top = top->next;
    return data;
}

int peek(){
    if(isEmpty()){
        return NULL;
    }
    return top->data;
}

int size(){
    int count = 0;
    Stack *temp = top;
    while (temp){
        temp = temp->next;
        count++;
    }
    return count;
}

int main(void)
{
    push(5);
    push(10);
    push(12);
    push(14);
    cout << pop() << '\n';
    cout << peek() << '\n';
    cout << size() << '\n';
    cout << pop() << '\n';
    cout << pop() << '\n';
    cout << pop() << '\n';
    cout << pop() << '\n';
}