#include "LCRSTree.h"

LCRSNode *LCRS_CreateNode(ElementType NewData) {
    LCRSNode *NewNode = (LCRSNode *) malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void LCRS_DestroyNode(LCRSNode *Node) {
    free(Node);
}

void LCRS_DestroyTree(LCRSNode * root) {
    if ( root -> RightSibling != NULL) {
        LCRS_DestroyTree(root -> RightSibling);
    }
    if (root -> LeftChild != NULL) {
        LCRS_DestroyTree(root -> LeftChild);
    }
    root -> LeftChild = NULL;
    root  -> RightSibling = NULL;

    LCRS_DestroyNode(root);
}

void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child) {
    if (Parent->LeftChild == NULL) {
        Parent->LeftChild = Child;
        return;
    }
    LCRSNode *TempNode = Parent->LeftChild;
    while (TempNode->RightSibling != NULL) {
        TempNode = TempNode->RightSibling;
    }
    TempNode->RightSibling = Child;
}

void LCRS_PrintTree(LCRSNode *Node, int Depth) {
    int i = 0;

    // 깊이 만큼 들여쓰기를 한다.
    for (i = 0; i < Depth; i++) {
        printf(" ");
    }

    // 노드에 담긴 데이터를 출력한다.
    printf("%c\n", Node->Data);

    if (Node -> LeftChild != NULL){
        LCRS_PrintTree(Node -> LeftChild , Depth+1);
    }
    if (Node -> RightSibling != NULL) {
        LCRS_PrintTree(Node -> RightSibling, Depth);
    }
}