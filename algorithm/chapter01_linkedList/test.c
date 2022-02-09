#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;
typedef struct tagNode
{
    ElementType Data;
    struct tagNode * NextNode;
} Node;

Node * SLL_CreateNode(ElementType NewData)
{
    Node * Current = (Node*) malloc(sizeof(Node));
    Current -> Data = NewData;
    Current -> NextNode = NULL;
    return Current;
}

void SLL_DestroyNode(Node *node){
    free(node);
}

void SLL_AppendNode(Node ** Head , Node * NewNode)
{
    if(*Head == NULL) {
        *Head = NewNode;
        return;
    }
    Node * Tail = (*Head);
    while ( Tail ->NextNode != NULL) {
        Tail = Tail -> NextNode;
    }
    Tail ->NextNode = NewNode;
}

void SLL_InsertAfter(Node * Current , Node * NewNode)
{
    NewNode -> NextNode = Current-> NextNode;
    Current -> NextNode = NewNode;
}

void SLL_InsertNewHead(Node ** Head , Node * NewHead)
{
    if(*Head == NULL) {
        (*Head) = NewHead;
        return;
    }
    NewHead -> NextNode = (*Head);
    (*Head) = NewHead;
}

void SLL_RemoveNode(Node ** Head , Node * Remove)
{
    if( *Head == Remove) {
        *Head = Remove -> NextNode;
        return;
    }
    Node *Current = *Head;
    while (Current != NULL && Current->NextNode != Remove) {
        Current = Current ->  NextNode;
    }
    if(Current != NULL) {
        Current -> NextNode = Remove -> NextNode;
    }
}

Node * SLL_GetNodeAt(Node * Head , int Location)
{
    Node *Current = Head;
    while (Current != NULL && --Location >= 0) {
        Current = Current->NextNode;
    }
    return Current;
}

int SLL_GETNodeCount(Node * Head)
{
    int count = 0;
    Node * Current = Head;
    while (Current != NULL) {
        Current = Current -> NextNode;
        count++;
    }
    return count;
}

void SLL_InsertBefore(Node ** Head , Node * Current , Node * NewHead)
{
    Node *tmp = (*Head);
    while (tmp != NULL && tmp -> NextNode != Current) {
        tmp = tmp -> NextNode;
    }
    NewHead -> NextNode = Current;
    tmp -> NextNode = NewHead;
}


int main(void)
{
    int i =0;
    int count = 0;
    Node * List = NULL;
    Node * Current = NULL;
    Node * NewNode = NULL;

    for (i = 0; i <5 ; ++i) {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List , NewNode);
    }
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List , NewNode);
    count = SLL_GETNodeCount(List);
    for ( i = 0; i < count; ++i) {
        Current = SLL_GetNodeAt(List,i);
        printf("List[%d] :  %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 After[2] ...... \n\n");
    Current = SLL_GetNodeAt(List,2);
    NewNode = SLL_CreateNode(3000);
    SLL_InsertAfter(Current,NewNode);
    count = SLL_GETNodeCount(List);
    for (i = 0; i < count; ++i) {
        Current = SLL_GetNodeAt(List,i);
        printf("List[%d] :  %d\n", i, Current->Data);
    }


    printf("\nInserting 1000 before[5] ...... \n\n");
    Current = SLL_GetNodeAt(List,5);
    NewNode = SLL_CreateNode(1000);
    SLL_InsertBefore(&List,Current,NewNode);
    count = SLL_GETNodeCount(List);
    for (i = 0; i < count; ++i) {
        Current = SLL_GetNodeAt(List,i);
        printf("List[%d] :  %d\n", i, Current->Data);
    }


    printf("\nDestroying List.. \n");
    for (i = 0; i < count; ++i) {
        Current = SLL_GetNodeAt(List,0);
        if(Current != NULL) {
            SLL_RemoveNode(&List , Current);
            SLL_DestroyNode(Current);
        }
    }
    return 0;
}