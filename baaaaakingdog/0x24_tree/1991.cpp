#include "bits/stdc++.h"

using namespace std;

typedef struct SBTNode {
    struct SBTNode *Left;
    struct SBTNode *Right;
    char Data;
} SBTNode;

SBTNode *createNode(char newData) {
    SBTNode *NewNode = (SBTNode *) malloc(sizeof(SBTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = newData;
    return NewNode;
}

void DestroyNode(SBTNode *Root) {
    free(Root);
}

void DestroyTree(SBTNode *Root) {
    if (Root == NULL) return;

    DestroyTree(Root->Left);
    DestroyTree(Root->Right);
    DestroyNode(Root);
}

void preOrder(SBTNode *Root) {
    if (Root == NULL) return;

    cout << Root->Data;
    preOrder(Root->Left);
    preOrder(Root->Right);
}

void InOrder(SBTNode *Root) {
    if (Root == NULL) return;

    InOrder(Root->Left);
    cout << Root->Data;
    InOrder(Root->Right);
}

void PostOrder(SBTNode *Root) {
    if (Root == NULL) return;

    PostOrder(Root->Left);
    PostOrder(Root->Right);
    cout << Root->Data;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    SBTNode *tree[26];
    for (int i = 0; i < n; ++i) {
        tree[i] = createNode(('A'+i));
    }
    while (n--) {
        char a, b, c;
        cin >> a >> b >> c;
        SBTNode *node = tree[a-'A'];
        if (b != '.') {
            node->Left = tree[b-'A'];
        }
        if (c != '.') {
            node->Right = tree[c-'A'];
        }
    }
    preOrder(tree[0]);
    cout<<'\n';
    InOrder(tree[0]);
    cout<<'\n';
    PostOrder(tree[0]);
    cout<<'\n';
}