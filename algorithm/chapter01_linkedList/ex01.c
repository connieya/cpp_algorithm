#include "stdio.h"
#include "malloc.h"

typedef struct tagNode
{
    int Data;
    struct tagNode* NextNode;
} Node;

Node * SLL_CreateNode(int newData)
{
    Node * NewNode = (Node *) malloc(sizeof(Node));
    NewNode ->Data = newData;
    NewNode -> NextNode = NULL;

    return NewNode;
}
void SLL_AppendNode(Node ** Head , Node * NewNode)
{
    if ((*Head) == NULL) {
        *Head = NewNode;
    }else {
        Node * Tail = (*Head);
        while (Tail -> NextNode != NULL) {
            Tail = Tail -> NextNode;
        }
        Tail -> NextNode = NewNode;
    }
}

Node * SLL_GetNodeAt(Node * Head , int Location)
{
    Node * Current = Head;
    while (Current -> NextNode != NULL && --Location >= 0) {
        Current = Current -> NextNode;
    }
    return Current;
}

void SLL_RemoveNode(Node ** Head , Node * Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove -> NextNode;
    }else {
        Node * Current = *Head;
        while (Current != NULL && Current -> NextNode != Remove) {
            Current = Current -> NextNode;
        }
        if(Current != NULL) {
            Current -> NextNode = Remove -> NextNode;
        }
    }
}

void SLL_DestroyNode(Node * node) {
    free(node);
}

void SLL_InsertAfter(Node * Current , Node * NewNode)
{
    NewNode -> NextNode = Current->NextNode;
    Current -> NextNode = NewNode;
}

int SLL_GetNodeCount(Node * Head)
{
    int count = 0;
    Node * Current = Head;
    while (Current->NextNode != NULL) {
        count++;
        Current = Current->NextNode;
    }
    return count;
}

int main(void)
{
    Node * List = NULL;
    Node * MyNode  = NULL;
    SLL_AppendNode(&List , SLL_CreateNode(117));
    SLL_AppendNode(&List , SLL_CreateNode(119));
    SLL_AppendNode(&List , SLL_CreateNode(212));

    MyNode = SLL_GetNodeAt(List , 1);
    printf("%d \n" , MyNode -> Data);

    SLL_RemoveNode(&List , MyNode);
    SLL_DestroyNode(MyNode);

}