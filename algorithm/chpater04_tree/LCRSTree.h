//#ifndef C_CPP_ALGORITHM_LCRSTREE_H
//#define C_CPP_ALGORITHM_LCRSTREE_H

#ifndef LCR_TREE_H
#define LCR_TREE_H


#include "stdio.h"
#include "stdlib.h"

typedef char ElementType;

typedef struct tagLCRSNode
{
    struct tagLCRSNode * LeftChild;
    struct tagLCRSNode * RightSibling;

    ElementType Data;

} LCRSNode;

LCRSNode * LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode * Node);
void LCRS_DestroyTree(LCRSNode * Root);

void LCRS_AddChildNode(LCRSNode * ParentNode , LCRSNode *ChildNode);
void LCRS_PrintTree(LCRSNode * Node , int Depth);

#endif //C_CPP_ALGORITHM_LCRSTREE_H
