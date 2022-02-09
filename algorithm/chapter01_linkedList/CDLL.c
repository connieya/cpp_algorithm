#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode * PrevNode;
    struct tagNode * NextNode;
} Node;


Node * CDLL_CreateNode(ElementType NewData)
{
    Node * NewNode = (Node *) malloc(sizeof(Node));
    NewNode -> Data = NewData;
    NewNode -> PrevNode = NULL;
    NewNode -> NextNode = NULL;

    return NewNode;
}

void CDLL_DestroyNode(Node * Node)
{
    free(Node);
}

void CDLL_AppendNode(Node ** Head , Node * NewNode)
{
    if( *Head == NULL) {
        *Head = NewNode;
        (*Head) -> NextNode = *Head;
        (*Head) -> PrevNode = *Head;
    }else {
        Node * Tail = (*Head) -> PrevNode;
       Tail->NextNode -> PrevNode = NewNode;
       Tail -> NextNode = NewNode;
       NewNode -> PrevNode = Tail;
       NewNode -> NextNode = *Head;

    }
}

void CDLL_InsertAfter(Node * Current , Node * NewNode)
{
    NewNode -> NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

void CDLL_RemoveNode(Node ** Head , Node * Remove)
{
    if(*Head == Remove) {
        (*Head) -> PrevNode -> NextNode = (*Head) -> NextNode;
        (*Head) -> NextNode -> PrevNode = (*Head) -> PrevNode;
        (*Head) -> NextNode = NULL;
        (*Head) -> PrevNode = NULL;

    }else {
        Node *Temp = Remove;
        Remove -> PrevNode ->NextNode = Temp -> NextNode;
        Remove -> NextNode -> PrevNode = Temp -> PrevNode;
        Remove -> NextNode = NULL;
        Remove -> PrevNode = NULL;
    }
}

Node * CDLL_GetNodeAt(Node * Head , int Location)
{
    Node * Current = Head;
    while (Current != NULL && --Location >= 0) {
        Current = Current -> NextNode;
    }
    return Current;
}

int CDLL_GetNodeCount(Node * Head)
{
    unsigned int Count = 0;
    Node * Current = Head;
    while (Current != NULL) {
        Current = Current ->NextNode;
        Count++;
        if(Current == Head) {
            break;
        }
    }
    return Count;
}

void PrintNode(Node * _Node)
{
    if (_Node -> PrevNode == NULL)
        printf("Prev : NULL");
    else
        printf("Prev : %d ", _Node -> PrevNode -> Data);

    printf("Current : %d", _Node -> Data);

    if (_Node -> NextNode == NULL)
        printf("Next : NULL \n");
    else
        printf("Next :  %d \n", _Node -> NextNode -> Data);
}

int main(void)
{
    int count = 0;
    Node * List = NULL;
    Node * NewNode = NULL;
    Node * Current = NULL;

    for (int i = 0; i < 5; ++i) {
        NewNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&List,NewNode);
    }
    count = CDLL_GetNodeCount(List);
    for (int i = 0; i < count; ++i) {
        Current = CDLL_GetNodeAt(List,i);
        printf("List[%d] : %d\n", i , Current->Data);
    }
}