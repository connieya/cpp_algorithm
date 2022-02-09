#include "stdlib.h"
#include "stdio.h"
#include "string.h"


typedef enum
{
    LEFT_PARENTHESIS = '(',RIGHT_PARENTHESIS = ')',
    PLUS = '+' , MINUS = '-' , MULTIPLY = '*' , DIVIDE ='/',
    SPACE =' ' , OPERAND
} SYMBOL;

typedef struct tagNode {
    char *Data;
    struct tagNode *NextNode;
} Node;

typedef struct tagLinkedListStack {
    Node *List;
    Node *Top;
} LinkedListStack;

void createStack(LinkedListStack **stack) {
    (*stack) = (LinkedListStack *) malloc(sizeof(LinkedListStack));
    (*stack)->List = NULL;
    (*stack)->Top = NULL;
}

int isEmpty(LinkedListStack *Stack) {
    return (Stack->List == NULL);
}

Node *Pop(LinkedListStack *Stack) {
    /* 현재 최상위 노드의 주소를 다른 포인터에 복사해 둔다. */
    Node *TopNode = Stack->Top;
    if (Stack->List == Stack->Top) {
        Stack->List = NULL;
        Stack->Top = NULL;
    } else {
        Node *CurrentTop = Stack->List;
        while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
            CurrentTop = CurrentTop->NextNode;
        }
        Stack->Top = CurrentTop;
        CurrentTop->NextNode = NULL;
    }
    return TopNode;
}

void destroyNode(Node *_Node) {
    free(_Node->Data);
    free(_Node);
}


void destroyStack(LinkedListStack *stack) {
    while (isEmpty(stack)) {
        Node *Popped = Pop(stack);
        destroyNode(Popped);
    }
    free(stack);
}

Node *createNode(char *NewData) {
    Node *NewNode = (Node *) malloc(sizeof(Node));
    NewNode->Data = (char *) malloc(sizeof(NewData) + 1);
    strcpy(NewNode->Data, NewData);

    NewNode->NextNode = NULL;
    return NewNode;
}


void Push(LinkedListStack *Stack, Node *NewNode) {
    if (Stack->List == NULL) {
        Stack->List = NewNode;
    } else {
        Node *OldTop = Stack->List;
        while (OldTop->NextNode != NULL) {
            OldTop = OldTop->NextNode;
        }
        OldTop->NextNode = NewNode;
    }
    Stack->Top = NewNode;
}


Node *LLS_Top(LinkedListStack *Stack) {
    return Stack->Top;
}

int getSize(LinkedListStack *Stack) {
    int count = 0;
    Node *Current = Stack->List;
    while (Current != NULL) {
        Current = Current->NextNode;
        count++;
    }
    return count;
}

char NUMBER [] = {'0','1','2','3','4','5','6','7','8','9','.'};

int IsNumber(char Cipher)
{
    int len = sizeof(NUMBER);
    for (int i = 0; i < len; ++i) {
        if (Cipher == NUMBER[i])
            return 1;
    }
    return 0;
}

unsigned int GetNextToken(char * Expression , char * Token , int * TYPE)
{
    unsigned int i= 0;
    for (i = 0; Expression[i] ; ++i) {
        Token[i] = Expression[i];
        if (IsNumber(Expression[i]) == 1) {
            *TYPE = OPERAND;
            if (IsNumber(Expression[i+1] != 1))
                break;
        }else {
            *TYPE = Expression[i];
            break;
        }
    }
    Token[++i] ='\0';
    return i;
}

int GetPriority(char Operator , int InStack)
{
    int Priority = -1;

    switch (Operator) {
        case LEFT_PARENTHESIS:
            if (InStack)
                Priority = 3;
            else
                Priority = 0;
            break;
        case MULTIPLY:
        case DIVIDE:
            Priority =1;
            break;
        case PLUS:
        case MINUS:
            Priority = 2;
            break;
    }
    return Priority;
}

int main(void)
{

}