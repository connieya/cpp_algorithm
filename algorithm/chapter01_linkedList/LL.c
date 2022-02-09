#include "LL.h"

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

int SLL_CetNodeCount(Node * Head)
{
    int count = 0;
    Node * Current = Head;
    while (Current != NULL) {
        Current = Current -> NextNode;
        count++;
    }
    return count;
}


