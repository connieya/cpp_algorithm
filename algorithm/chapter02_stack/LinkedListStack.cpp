#include "bits/stdc++.h"

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


int main() {
    int count = 0;
    Node *Popped;

    LinkedListStack *Stack;

    createStack(&Stack);
    Push(Stack, createNode("abc"));
    Push(Stack, createNode("def"));
    Push(Stack, createNode("efg"));
    Push(Stack, createNode("hij"));

    count = getSize(Stack);
    printf("size : %d , top : %s\n\n", count, LLS_Top(Stack)->Data);
    for (int i = 0; i < count; ++i) {
        if (isEmpty(Stack)) break;

        Popped = Pop(Stack);

        printf("Popped :  %s ", Popped->Data);

        destroyNode(Popped);

        if (!isEmpty(Stack)) {
            printf("Current top : %s\n", LLS_Top(Stack)->Data);
        } else {
            printf("Stack is Empty \n");
        }
    }
    destroyStack(Stack);
}