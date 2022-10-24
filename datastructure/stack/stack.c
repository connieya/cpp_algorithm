#include "stdio.h"
#include "stdlib.h"
#define SIZE 100

typedef struct StackType {
    int arr[SIZE];
    int top;
} StackType;

void init(StackType *s){
    s->top = -1;
}

int isEmpty(StackType *s){
    return s->top == -1;
}

int isFull(StackType *s){
    return s->top == SIZE-1;
}

void push(StackType *s , int value){
    if(isFull(s)){
        printf("Stack is Full..");
        exit(0);
    }
    printf("\n pushed :   %d \n",value);
    s->arr[++(s->top)] = value;
}

int pop(StackType *s) {
   if(isEmpty(s)){
       printf("stack is empty.");
       exit(1);
   }
    return s->arr[(s->top)--];
}

int peek(StackType *s){
    if(isEmpty(s)){
        printf("stack is Empty ...");
        exit(1);
    }
    return s->arr[s->top];
}

int main(void)
{
    StackType s;
    StackType s2;
    init(&s);
    push(&s,3);
    push(&s,2);
    push(&s,1);
    printf("peek : %d \n", peek(&s));
    printf("popped : %d \n", pop(&s));
    printf("peek : %d \n", peek(&s));;
    init(&s2);
    return 0;
}