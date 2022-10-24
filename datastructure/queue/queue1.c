#include "stdlib.h"

const int MX = 1000005;
 int arr[MX];

int head = 0 , tail = 0;

void push(int x){
    arr[tail++] = x;
}

void pop(){
    head++;
}
int front(){
    return arr[head];
}

int back(){
    return arr[tail-1];
}
