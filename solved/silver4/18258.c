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
    int n;
    scanf("%d", &n);
    CircularQueue *queue;
    createQueue(&queue, n);
    while (n--) {
        char command[6];
        scanf("%s", command);
        if (command[1] == 'u') {
            int x;
            scanf("%d", &x);
            enQueue(queue, x);

        } else if (command[1] == 'o') {
            if (isEmpty(queue)) {
                printf("%d \n", -1);
            } else {
                printf("%d \n", deQueue(queue));
            }
        } else if (command[0] == 's') {
            printf("%d \n", size(queue));
        } else if (command[0] == 'e') {
            printf("%d \n", isEmpty(queue));
        } else if (command[0] == 'f') {
            if (isEmpty(queue)) {
                printf("%d \n", -1);
            } else {
                printf("%d \n", front(queue));
            }
        } else {
            if (isEmpty(queue)) {
                printf("%d \n", -1);
            } else {
                printf("%d \n", back(queue));
            }
        }
    }
}