#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef char ElementType;

typedef struct tagETNode {
    struct tagETNode *Left;
    struct tagETNode *Right;

    ElementType Data;
} ETNode;

ETNode *ET_CreateNode(ElementType NewData) {
    ETNode *NewNode = (ETNode *) malloc(sizeof(ETNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void ET_DestroyNode(ETNode *Node) {
    free(Node);
}

void ET_DestroyTree(ETNode *Root) {
    if (Root == NULL) {
        return;
    }
    ET_DestroyTree(Root->Left);
    ET_DestroyTree(Root->Right);
    ET_DestroyNode(Root);
}

void ET_PreOrderPrintTree(ETNode *Root) {
    if (Root == NULL) return;

    printf("%c ", Root->Data);
    ET_PreOrderPrintTree(Root->Left);
    ET_PreOrderPrintTree(Root->Right);
}

void ET_InOrderPrintTree(ETNode *Root) {
    if (Root == NULL) return;

    printf("(");
    ET_InOrderPrintTree(Root->Left);
    printf("%c ", Root->Data);
    ET_InOrderPrintTree(Root->Right);
    printf(")");
}

void ET_PostOrderPrintTree(ETNode *Root) {
    if (Root == NULL) {
        return;
    }
    ET_PostOrderPrintTree(Root->Left);
    ET_PostOrderPrintTree(Root->Right);
    printf("%c ", Root->Data);
}


void ET_BuildExpressionTree(char *PostfixExpression, ETNode **Node) {
    int len = strlen(PostfixExpression);
    char Token = PostfixExpression[len - 1];
    PostfixExpression[len - 1] = '\0';

    switch (Token) {
        case '+':
        case '-':
        case '*':
        case '/':
            (*Node) = ET_CreateNode(Token);
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
            break;
            // 피연산자인 경우
        default:
            (*Node) = ET_CreateNode(Token);
            break;
    }
}

double ET_Evaluate(ETNode *Tree) {
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (Tree == NULL)
        return 0;

    switch (Tree->Data) {
        case '+':
        case '-':
        case '*':
        case '/':
            Left = ET_Evaluate(Tree->Left);
            Right = ET_Evaluate(Tree->Right);

            if (Tree->Data == '+') Result = Left + Right;
            else if (Tree->Data == '-') Result = Left - Right;
            else if (Tree->Data == '*') Result = Left * Right;
            else if (Tree->Data == '/') Result = Left / Right;

            break;

            // 피연산자인 경우
        default:
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp);
            break;
    }
    return Result;
}

int main(void) {
    ETNode *Root = NULL;

    char PostfixExpression[20] = "71*52-/";
    ET_BuildExpressionTree(PostfixExpression, &Root);

    // 트리 출력
    printf("Preorder...\n");
    ET_PreOrderPrintTree(Root);
    printf("\n\n");

    printf("Inorder...\n");
    ET_InOrderPrintTree(Root);
    printf("\n\n");

    printf("PostOrder...\n");
    ET_PostOrderPrintTree(Root);
    printf("\n\n");

    printf("Evaluation Result : %f \n", ET_Evaluate(Root));

    // 트리 소멸시키기
    ET_DestroyTree(Root);
    return 0;

}
