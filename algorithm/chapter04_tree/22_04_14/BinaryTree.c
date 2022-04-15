#include "stdio.h"
#include "stdlib.h"

typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode * Left;
    struct tagSBTNode * Right;

    ElementType Data;
} SBTNode;

SBTNode  * SBT_CreateNode(ElementType NewData)
{
    SBTNode * NewNode = (SBTNode*) malloc(sizeof(SBTNode));
    NewNode->Left =NULL;
    NewNode->Right =NULL;
    NewNode->Data = NewData;
    return NewNode;
}

void SBT_DestroyNode(SBTNode * Node)
{
    free(Node);
}

void SBT_DestroyTree(SBTNode * Node)
{
    if (Node == NULL)
        return;
    SBT_DestroyTree(Node->Left);
    SBT_DestroyTree(Node->Right);
    SBT_DestroyNode(Node);
}

