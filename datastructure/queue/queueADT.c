#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue_type {
    struct node * front;
    struct node * rear;
    int size;
} Queue;

int get_size(Queue q){
    return q.size;
}

Queue create(){
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue q, int data){
    Node * new_node = malloc(sizeof(new_node));
    new_node->data = data;
    new_node->next = NULL;
    if(q.front == NULL){

    }else {
        q.rear->next = new_node;
        q.rear = new_node;
    }
    q.size++;
}