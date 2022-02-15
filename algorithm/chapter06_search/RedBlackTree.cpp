#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagRBTNode {
    struct tagRBTNode *Parent;
    struct tagRBTNode *Left;
    struct tagRBTNode *Right;

    enum {
        RED, BLACK
    } Color;

    ElementType Data;

} RBTNode;


/* 우회전  => 왼쪽 자식과 부모의 위치를 교환 */
void RBT_RotateRight(RBTNode **Root, RBTNode *Parent) {
    RBTNode *LeftChild = Parent->Left;
    Parent->Left = LeftChild->Right;

    if (LeftChild->Right != NULL) {
        LeftChild->Right->Parent = Parent;
    }
    LeftChild->Parent = Parent->Parent;

    if (Parent->Parent == NULL) { // 부모가 널이라면 즉, 루트 노드라면
        (*Root) = LeftChild;
    } else {
        if (Parent == Parent->Parent->Left)
            Parent->Parent->Left = LeftChild;
        else
            Parent->Parent->Right = LeftChild;
    }
    LeftChild->Right = Parent;
    Parent->Parent = LeftChild;
}

void RBT_RotateLeft(RBTNode ** Root , RBTNode * Parent)
{
    RBTNode *RightChild = Parent->Right;
    Parent->Right = RightChild->Left;

    if (RightChild->Left != NULL){
        RightChild->Left->Parent = Parent;
    }
    RightChild ->Parent = Parent->Parent;
    if (Parent->Parent == NULL) {
        (*Root) == RightChild;
    }else {
        if (Parent == Parent->Parent->Left){
            Parent->Parent->Left = RightChild;
        }else {
            Parent->Parent->Right = RightChild;
        }
    }
    RightChild->Left = Parent;
    Parent->Parent = RightChild;
}

void RBT_RebuildAfterInsert(RBTNode **Root, RBTNode *X) {
    while (X != (*Root) && X->Parent->Color == tagRBTNode::RED) {
        if (X->Parent == X->Parent->Parent->Left) // 부모 노드가 할아버지 노드의 왼쪽 자식인 경우
        {
            RBTNode *Uncle = X->Parent->Parent->Right;
            if (Uncle->Color == tagRBTNode::RED) { //  삼촌이 빨간색인 경우
                X->Parent->Color = tagRBTNode::BLACK;
                Uncle->Color = tagRBTNode::BLACK;
                X->Parent->Parent->Color = tagRBTNode::RED;

                X = X->Parent->Parent;
            } else { // 삼촌이 검은색일 경우
                if (X == X->Parent->Right) {
                    X = X->Parent;
                    RBT_RotateLeft(Root, X);
                }
                X->Parent->Color = tagRBTNode::BLACK;
                X->Parent->Parent->Color = tagRBTNode::RED;
                RBT_RotateRight(Root,X->Parent->Parent);
            }
        } else { // 부모 노드가 할아버지 노드의 오른쪽 자식인 경우
            RBTNode * Uncle = X->Parent->Parent->Left;

        }
    }
    (*Root) ->Color = tagRBTNode::BLACK; // 루트 노드는 반드시 검은색이어야 한다.
}

void RBT_InsertNode(RBTNode **Tree, RBTNode *NewNode) {
    NewNode->Color = tagRBTNode::RED;
    NewNode->Left = Nil;
    NewNode->Right = Nil;
}