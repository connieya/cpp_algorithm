#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode * PreNode;
    struct tagNode * NextNode;
} Node;


Node * DLL_CreateNode(ElementType NewData)
{
    Node * NewNode = (Node *) malloc(sizeof(Node));
    NewNode -> Data = NewData;
    NewNode -> PreNode = NULL;
    NewNode -> NextNode = NULL;

    return NewNode;
}

void DLL_DestroyNode(Node * Node)
{
    free(Node);
}

void DLL_AppendNode(Node ** Head , Node * NewNode)
{
    if((*Head) == NULL) {
        *Head = NewNode;
    }else {
        Node * Tail = (*Head);
        while (Tail->NextNode != NULL) {
            Tail = Tail -> NextNode;
        }
        Tail -> NextNode = NewNode;
        NewNode -> PreNode = Tail;
    }
}

void DLL_InsertAfter(Node * Current , Node * NewNode)
{
    NewNode -> NextNode = Current->NextNode;
    NewNode->PreNode = Current;

    if(Current -> NextNode != NULL) {
        Current-> NextNode -> PreNode = NewNode;
    }
    Current -> NextNode = NewNode;
}

void DLL_RemoveNode(Node ** Head , Node * Remove)
{
    if(*Head == Remove) {
        *Head = Remove -> NextNode;
        if( (*Head) != NULL) {
            (*Head)->PreNode = NULL;
        }
        Remove->PreNode= NULL;
        Remove->NextNode= NULL;
    } else {
        Node * Temp = Remove;
        if (Remove -> PreNode != NULL) {
            Remove -> PreNode -> NextNode = Temp -> NextNode;
        }
        if (Remove -> NextNode != NULL) {
            Remove -> NextNode ->PreNode = Temp -> PreNode;
        }
        Remove->PreNode = NULL;
        Remove->NextNode = NULL;
    }
}

Node * DLL_GetNodeAt(Node * Head , int Location)
{
    Node * Current = Head;
    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current -> NextNode;
    }
    return Current;
}

int DLL_GetNodeCount(Node * Head)
{
    unsigned int Count = 0;
    Node * Current = Head;
    while (Current != NULL) {
        Current = Current -> NextNode;
        Count++;
    }
    return Count;
}

int main(void)
{
    int Count = 0;
    Node * List = NULL;
    Node * NewNode = NULL;
    Node * Current = NULL;
    for (int i = 0; i < 5; ++i) {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List,NewNode);
    }

    Count = DLL_GetNodeCount(List);
    for (int i = 0; i < Count; ++i) {
        Current = DLL_GetNodeAt(List,i);
        printf("List[%d] : %d\n",i,Current ->Data);
    }
}