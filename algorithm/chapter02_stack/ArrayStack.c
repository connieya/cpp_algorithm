#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagNode {
    ElementType Data;

} Node;

typedef struct tagArrayStack {
    int Capacity;
    int Top;
    Node *Nodes;
} ArrayStack;

void CreateStack(ArrayStack **Stack, int capacity) {
//    스택을 자유 저장소에 생성
    (*Stack) = (ArrayStack *) malloc(sizeof(ArrayStack));

    /* 입력 된 Capacity 만큼의 노드를 자유 저장소에 생성 */
    (*Stack)->Nodes = (Node *) malloc(sizeof(Node) * capacity);

    (*Stack)->Capacity = capacity;
    (*Stack)->Top = 0;
}

void DestroyStack(ArrayStack * stack)
{
    /* 노드를 자유 저장소에서 해제*/
    free(stack -> Nodes);

    /* 스택을 자유 저장소에서 해제*/
    free(stack);

}

void Push(ArrayStack * Stack , ElementType Data) {
    int position = Stack -> Top;
    Stack -> Nodes[position].Data = Data;
    Stack -> Top++;
}

ElementType Pop(ArrayStack * Stack)
{
    int position = Stack -> Top-1;
    Stack -> Top--;
    return Stack -> Nodes[position].Data;
}

ElementType Top(ArrayStack * Stack) {
    int position = Stack -> Top-1;
    return Stack -> Nodes[position].Data;
}

int size(ArrayStack * Stack) {
    return Stack -> Top;
}

int isEmpty(ArrayStack * Stack) {
    return (Stack -> Top == 0);
}

int isFull(ArrayStack * Stack) {
    return Stack->Capacity <= Stack ->Top;
}

int main(void)
{
    ArrayStack * Stack = NULL;
    CreateStack(&Stack , 10);

    Push(Stack,3);
    Push(Stack,37);
    Push(Stack,11);
    Push(Stack,12);

    printf("capacity : %d , size : %d , top : %d \n\n",Stack -> Capacity , size(Stack) , Top(Stack));
    for (int i = 0; i < 4; ++i) {
        if (isEmpty(Stack)) break;

        printf("Popped : %d ," , Pop(Stack));

        if (!isEmpty(Stack)) {
            printf("Current Top : %d\n" , Top(Stack));
        }else {
            printf("Stack is Empty");
        }
    }
    DestroyStack(Stack);

}