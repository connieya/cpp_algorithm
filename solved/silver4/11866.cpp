#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagNode {
    ElementType Data;
} Node;

typedef struct tagCircularQueue {
    int capacity;
    int front;
    int rear;
    Node *nodes;
} CircularQueue;

void createQueue(CircularQueue **queue, int capacity) {
    (*queue) = (CircularQueue *) malloc(sizeof(CircularQueue));
    (*queue)->nodes = (Node *) malloc(sizeof(Node) * (capacity + 1));
    (*queue)->capacity = capacity;
    (*queue)->front = 0;
    (*queue)->rear = 0;
}

void enQueue(CircularQueue *queue, ElementType data) {
    int position = 0;
    if (queue->rear == queue->capacity) {
        position = queue->rear;
        queue->rear = 0;
    } else {
        position = queue->rear++;
    }
    queue->nodes[position].Data = data;
}

ElementType deQueue(CircularQueue *queue) {
    int position = queue->front;
    if (queue->front == queue->capacity) {
        queue->front = 0;
    } else {
        queue->front++;
    }
    return queue->nodes[position].Data;
}

int isEmpty(CircularQueue *queue) {
    return queue->front == queue->rear;
}

int size(CircularQueue *queue) {
    if (queue->front <= queue->rear) return queue->rear - queue->front;
    return queue->rear + (queue->capacity - queue->front) + 1;
}

int front(CircularQueue *queue) {
    return queue->nodes[queue->front].Data;
}

int back(CircularQueue *queue) {
    int position = queue->rear-1;
    return queue->nodes[position].Data;
}


int main(void) {
    int n ,k;
    scanf("%d %d", &n, &k);
    CircularQueue *queue;
    createQueue(&queue, n);
    for (int i = 0; i < n; ++i) {
        enQueue(queue,i+1);
    }
    printf("<");
    while (size(queue) > 1){
        for (int i = 0; i < k-1; ++i) {
            int pop = deQueue(queue);
            enQueue(queue,pop);
        }
        int remove = deQueue(queue);
        printf("%d, ",remove);
    }
    printf("%d>", deQueue(queue));
}