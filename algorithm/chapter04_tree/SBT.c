#include "stdio.h"
#include "malloc.h"

typedef char ElementType;

typedef struct tagSBTNode {
    struct tagSBTNode *Left;
    struct tagSBTNode *Right;
    ElementType Data;
} SBTNode;

SBTNode *SBT_CreateNode(ElementType NewData) {
    SBTNode *NewNode = (SBTNode *) malloc(sizeof(SBTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void SBT_DestroyNode(SBTNode *Node) {
    free(Node);
}

// 전위 순회 출력
void SBT_PreorderPrintTree(SBTNode *Node) {
    if (Node == NULL) return;

    // 루트 노드 출력
    printf(" %c", Node->Data);
    // 왼쪽 하위 노드 출력
    SBT_PreorderPrintTree(Node->Left);
    // 오른쪽 하위 노드 출력
    SBT_PreorderPrintTree(Node->Right);
}


// 중위 순회 출력 => 왼쪽 루트 오른쪽
void SBT_InorderPrintTree(SBTNode *Node) {
    if (Node == NULL) return;

    // 왼쪽 하위 트리 출력
    SBT_InorderPrintTree(Node->Left);

    // 루트 노드 출력
    printf(" %c", Node->Data);

    // 오른쪽 하위 트리 출력
    SBT_InorderPrintTree(Node->Right);
}

// 후위 순회 출력 => 왼쪽 오른쪽 루트
void SBT_PostorderPrintTree(SBTNode *Node) {
    if (Node == NULL) return;

    // 왼쪽 하위 트리 출력
    SBT_PostorderPrintTree(Node->Left);

    // 오른쪽 하위 트리 출력
    SBT_PostorderPrintTree(Node->Right);

    // 루트 노드 출력
    printf(" %c", Node->Data);
}


// 후위 순회를 응용한 트리 소멸 함수
void SBT_DestroyTree(SBTNode *Node) {
    if (Node == NULL) return;

    // 왼쪽 하위 트리 소멸
    SBT_DestroyTree(Node->Left);
    // 오른쪽 하위 트리 소멸
    SBT_DestroyTree(Node->Right);

    // 루트 노드 소멸
    SBT_DestroyNode(Node);
}


int main(void) {

    // 노드 생성
    SBTNode *A = SBT_CreateNode('A');
    SBTNode *B = SBT_CreateNode('B');
    SBTNode *C = SBT_CreateNode('C');
    SBTNode *D = SBT_CreateNode('D');
    SBTNode *E = SBT_CreateNode('E');
    SBTNode *F = SBT_CreateNode('F');
    SBTNode *G = SBT_CreateNode('G');

    // 트리에 노드 추가
    A->Left = B;
    B->Left = D;
    B->Right = E;

    A->Right = C;
    C->Left = F;
    C->Right = G;
      /*   A
       B      C

    D    E  F    G
       */
    printf("PreOrder .... \n");
    SBT_PreorderPrintTree(A);
    printf("\n\n");

    printf("InOrder .... \n");
    SBT_InorderPrintTree(A);
    printf("\n\n");

    printf("PostOrder...... \n");
    SBT_PostorderPrintTree(A);
    printf("\n\n");

}