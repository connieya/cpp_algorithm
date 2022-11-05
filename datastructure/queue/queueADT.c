#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue_type {
    Node *front;
    Node *rear;
    int size;
} Queue;

int isEmpty(Queue * queue);
void Enqueue(Queue * queue , int data) ;
int Dequeue(Queue * queue);
void initQueue(Queue *queue);

int get_size(Queue q) {
    return q.size;
}
void initQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

int isEmpty(Queue * queue) {
    return queue->size == 0;
}

void Enqueue(Queue *queue, int data) {
    Node * now = (Node*) malloc(sizeof(Node));
    now->data =data;
    now->next = NULL;

    if(isEmpty(queue)){
        queue->front = now;
    }else {
        queue->rear->next = now;
    }
    queue->rear = now;
    queue->size++;
}

int Dequeue(Queue *queue) {
    Node * now;
    int res = 0;
    if(isEmpty(queue)){
        return res;
    }
    now = queue->front;
    res = now->data;
    queue->front = now->next;
    free(now);
    queue->size--;
    return res;
}

int main(void)
{
    int i;
    Queue queue;
    initQueue(&queue);
    for(i=1; i<=5; i++) {
        Enqueue(&queue , i);
    }
    while (!isEmpty(&queue)){
        printf("%d \n", Dequeue(&queue)); // 1 2 3 4 5
    }
    Enqueue(&queue,3);
    Enqueue(&queue,6);
    Enqueue(&queue,8);
    Enqueue(&queue,4);
    Enqueue(&queue,7); // 3 6 8 4 7
    printf("%d\n", Dequeue(&queue)); // 3 출력 6 8 4 7
    Enqueue(&queue,1); // 6 8 4 7 1
    printf("%d \n", Dequeue(&queue)); //6 출력 8 4 7 1

    while (!isEmpty(&queue)) {
        printf("%d\n", Dequeue(&queue)); // 8 => 4 => 7 => 1
    }
}