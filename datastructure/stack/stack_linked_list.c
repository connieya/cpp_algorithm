#include "stdio.h"
#include "stdlib.h"

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

int is_empty(){
    return top == NULL;
}

int pop() {
    if(is_empty()){
        return NULL;
    }
    int data = top->data;
    top = top->next;
    return data;
}

int peek(){
    if(is_empty()){
        return NULL;
    }
    return top->data;
}

int main(void)
{

}