﻿#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct tagNode {
    char *Data;
    struct tagNode *NextNode;
} Node;

typedef struct tagLinkedQueue {
    Node *Front;
    Node *Rear;
    int Count;
} LinkedQueue;

int LQ_IsEmpty(LinkedQueue * Queue)
{
    return (Queue->Front == NULL);
}

Node * LQ_Dequeue(LinkedQueue * Queue)
{
    Node * Front = Queue->Front;
    if (Queue->Front->NextNode ==NULL)
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else {
        Queue->Front = Queue->Front->NextNode;
    }
    Queue->Count--;
    return Front;
}

Node * LQ_CreateNode(char * NewData)
{
    Node * NewNode = (Node *) malloc(sizeof(Node));
    NewNode->Data = (Node *) malloc(sizeof(NewData)+1);
    strcpy(NewNode->Data, NewData);
    NewNode->NextNode = NULL;
    return NewNode;

}

void LQ_CreateQueue(LinkedQueue **Queue) {
    (*Queue) = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

void LQ_DestroyNode(Node * _Node)
{
    free(_Node->Data);
    free(_Node);
}

void LQ_DestroyQueue(LinkedQueue *Queue) {
    while (!LQ_IsEmpty(Queue)) {
        Node *Popped = LQ_Dequeue(&Queue);
        LQ_DestroyNode(Popped);
    }
    free(Queue);
}

void LQ_Enqueue(LinkedQueue *Queue, Node *NewNode) {
    if (Queue->Front == NULL) {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    } else {
        Queue->Rear->NextNode =NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}




int main(void)
{
    Node * Popped;
    LinkedQueue * Queue;

    LQ_CreateQueue(&Queue);

    LQ_Enqueue(Queue, LQ_CreateNode("abc"));
    LQ_Enqueue(Queue, LQ_CreateNode("def"));
    LQ_Enqueue(Queue, LQ_CreateNode("efg"));
    LQ_Enqueue(Queue, LQ_CreateNode("hij"));

    printf("Queue Size : %d \n" ,Queue->Count);

    while (LQ_IsEmpty(Queue) == 0) {
        Popped = LQ_Dequeue(Queue);
        printf("Dequeue : %s \n",Popped->Data);
        LQ_DestroyNode(Popped);
    }
    LQ_DestroyQueue(Queue);
    return 0;
}