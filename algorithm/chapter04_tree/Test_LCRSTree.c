#include "stdio.h"
#include "stdlib.h"

typedef char ElementType;

typedef struct tagLCRSNode
{
    struct tagLCRSNode * LeftChild;
    struct tagLCRSNode * RightSibling;

    ElementType Data;

} LCRSNode;


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

void LCRS_PrintNodesAtLevel(LCRSNode* Root , int Level)
{
    int cnt = 0;
    while (cnt  != Level){

    }
}

int main(void)
{
    LCRSNode * Root = LCRS_CreateNode('A');

    LCRSNode * B = LCRS_CreateNode('B');
    LCRSNode * C = LCRS_CreateNode('C');
    LCRSNode * D = LCRS_CreateNode('D');
    LCRSNode * E = LCRS_CreateNode('E');
    LCRSNode * F = LCRS_CreateNode('F');
    LCRSNode * G = LCRS_CreateNode('G');
    LCRSNode * H = LCRS_CreateNode('H');
    LCRSNode * I = LCRS_CreateNode('I');
    LCRSNode * J = LCRS_CreateNode('J');
    LCRSNode * K = LCRS_CreateNode('K');

    // 트리에 노드 추가
    LCRS_AddChildNode(Root,B);
    LCRS_AddChildNode(B,C);
    LCRS_AddChildNode(B,D);
    LCRS_AddChildNode(D,E);
    LCRS_AddChildNode(D,F);

    LCRS_AddChildNode(Root,G);
    LCRS_AddChildNode(G,H);

    LCRS_AddChildNode(Root,I);
    LCRS_AddChildNode(I,J);
    LCRS_AddChildNode(J,K);

    // 트리 출력
    LCRS_PrintTree(Root,0);

    //트리 소멸
    LCRS_DestroyTree(Root);

    return 0;
}