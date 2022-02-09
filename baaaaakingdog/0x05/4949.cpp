#include "bits/stdc++.h"

using namespace std;

typedef char ElementType;

typedef struct tagNode {
    ElementType data;
} Node;

typedef struct ArrayStack {
    int top;
    Node *Nodes;
} ArrayStack;

void CreateStack(ArrayStack **Stack, int capacity) {
    (*Stack) = (ArrayStack *) malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = (Node *) malloc(sizeof(Node) * capacity);
    (*Stack)->top = 0;
}

void DestroyStack(ArrayStack *Stack) {
    free(Stack->Nodes);
    free(Stack);
}

void Push(ArrayStack *Stack, ElementType Data) {
    int position = Stack->top;
    Stack->Nodes[position].data = Data;
    Stack->top++;
}

ElementType Pop(ArrayStack *Stack) {
    int position = Stack->top - 1;
    Stack->top--;
    return Stack->Nodes[position].data;
}

ElementType Top(ArrayStack *Stack) {
    int position = Stack->top -1;
    return Stack->Nodes[position].data;
}

bool isEmpty(ArrayStack *Stack) {
    return Stack->top == 0;
}

bool check(ArrayStack *Stack, char ch) {
    if (isEmpty(Stack)) return false;

    if(ch == ']' && Top(Stack) == '[') return true;

    if (ch ==')' && Top(Stack) == '(') return true;

    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        string str;
        string ans = "yes";
        getline(cin, str);
        if (str == ".") break;
        ArrayStack *Stack = NULL;
        CreateStack(&Stack, 101);
        for (char ch: str) {
            if (ch == '[') {
                Push(Stack, ch);
                continue;
            }
            if (ch == '(') {
                Push(Stack, ch);
                continue;
            }
            if (ch == ']') {
                bool flag = check(Stack,ch);
                if (!flag){
                    ans = "no";
                    break;
                }
                Pop(Stack);
            }
            if (ch == ')') {
                bool flag = check(Stack,ch);
                if (!flag){
                    ans = "no";
                    break;
                }
                Pop(Stack);
            }
        }
        if(!isEmpty(Stack)){
            ans = "no";
        }
        cout << ans <<'\n';
    }
}