#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagBSTNode {
    struct tagBSTNode *Left;
    struct tagBSTNode *Right;

    ElementType Data;
} BSTNode;


BSTNode *BST_CreateNode(ElementType);

void BST_DestroyNode(BSTNode *Node);

void BST_DestroyTree(BSTNode *Tree);

BSTNode *BST_SearchNode(BSTNode *Tree, ElementType target);

BSTNode *BST_SearchMinNode(BSTNode *Tree);

void BST_InsertNode(BSTNode *Tree, BSTNode *Child);

BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *parent, ElementType target);

void BST_InorderPrintTree(BSTNode *Node);

BSTNode *BST_CreateNode(ElementType NewData) {
    BSTNode *NewNode = (BSTNode *) malloc(sizeof(BSTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void BST_DestroyTree(BSTNode *Tree) {
    if (Tree->Right != NULL)
        BST_DestroyTree(Tree->Right);

    if (Tree->Left != NULL)
        BST_DestroyTree(Tree->Left);

    Tree->Left = NULL;
    Tree->Right = NULL;
    BST_DestroyNode(Tree);
}

void BST_DestroyNode(BSTNode *Node) {
    free(Node);
}

BSTNode *BST_SearchNode(BSTNode *Tree, ElementType target) {
    if (Tree == NULL)
        return NULL;

    if (Tree->Data == target)
        return Tree;
    else if (Tree->Data > target)
        return BST_SearchNode(Tree->Left, target);
    else
        return BST_SearchNode(Tree->Right, target);
}

BSTNode *BST_SearchMinNode(BSTNode *Tree) {
    if (Tree == NULL)
        return NULL;

    if (Tree->Left == NULL)
        return Tree;
    else
        return BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode *Tree, BSTNode *Child) {
    if (Tree->Data < Child->Data) {
        if (Tree->Right == NULL)
            Tree->Right = Child;
        else
            BST_InsertNode(Tree->Right, Child);
    } else if (Tree->Data > Child->Data) {
        if (Tree->Left == NULL) {
            Tree->Left = Child;
        } else {
            BST_InsertNode(Tree->Left, Child);
        }
    }
}

BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *Parent, ElementType target) {
    BSTNode *Removed = NULL;
    if (Tree == NULL)
        return NULL;

    if (Tree->Data > target)
        Removed = BST_RemoveNode(Tree->Left, Tree, target);
    else if (Tree->Data < target)
        Removed = BST_RemoveNode(Tree->Right, Tree, target);
    else {
        Removed = Tree;
        /* 잎 노드인 경우 바로 삭제 */
        if (Tree->Left == NULL && Tree->Right == NULL) {
            if (Parent->Left == Tree)
                Parent->Left = NULL;
            else
                Parent->Right = NULL;
        } else {
            /* 자식이 양쪽 다 있는 경우*/
            if (Tree->Left != NULL && Tree->Right != NULL) {

                /*최소값 노드를 찾아 제거한 뒤 현재의 노드에 위치시칸다. */
                BSTNode *MINNode = BST_SearchMinNode(Tree->Right);
                MINNode = BST_RemoveNode(Tree, NULL, MINNode->Data);
                Tree->Data = MINNode->Data;
            } else {
                /* 자식이 하나만 있는 경우 */
                BSTNode *Temp = NULL;
                if (Tree->Left != NULL)
                    Temp = Tree->Left;
                else
                    Temp = Tree->Right;

                if (Parent->Left == Tree)
                    Parent->Left = Temp;
                else
                    Parent->Right = Temp;
            }
        }
    }
    return Removed;
}

void BST_InorderPrintTree(BSTNode *Node) {
    if (Node == NULL)
        return;

    /* 왼쪽 하위 트리 출력 */
    BST_InorderPrintTree(Node->Left);

    /* 루트 노드 출력*/
    printf("%d ", Node->Data);

    /* 오른쪽 하위 트리 출력 */
    BST_InorderPrintTree(Node->Right);
}

int main(void) {
    /* 노드 생성*/
    BSTNode *Tree = BST_CreateNode(123);
    BSTNode *Node = NULL;

    /* 트리에 노드 추가 */
    BST_InsertNode(Tree, BST_CreateNode(22));
    BST_InsertNode(Tree, BST_CreateNode(9918));
    BST_InsertNode(Tree, BST_CreateNode(424));
    BST_InsertNode(Tree, BST_CreateNode(17));
    BST_InsertNode(Tree, BST_CreateNode(3));

    BST_InsertNode(Tree, BST_CreateNode(98));
    BST_InsertNode(Tree, BST_CreateNode(34));

    BST_InsertNode(Tree, BST_CreateNode(760));
    BST_InsertNode(Tree, BST_CreateNode(317));
    BST_InsertNode(Tree, BST_CreateNode(1));

    /* 트리 출력 */
    BST_InorderPrintTree(Tree);
    printf("\n");

    /* 특정 노드 삭제 */
    printf("Removing 98... \n");
    Node = BST_RemoveNode(Tree , NULL, 98);
    BST_DestroyNode(Node);

    BST_InorderPrintTree(Tree);
    printf("\n");

    /* 새 노드 삽입 */
    printf("Inserting 111 ... \n");

    BST_InsertNode(Tree , BST_CreateNode(111) );
    BST_InorderPrintTree(Tree);
    printf("\n");

    /* 트리 소멸시키기 */
    BST_DestroyTree(Tree);
    return 0;
}