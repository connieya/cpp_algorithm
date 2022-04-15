#include "bits/stdc++.h"

using namespace std;

struct BST_Node {
    int data;
    BST_Node *Left_Child;
    BST_Node *Right_Child;
};

BST_Node *createNode(int num) {
    BST_Node *newNode = (BST_Node *) malloc(sizeof(BST_Node));
    newNode->Left_Child = NULL;
    newNode->Right_Child = NULL;
    newNode->data = num;
    return newNode;
}

void insertNode(BST_Node *root, BST_Node *child) {
    if (root->data > child->data) {
        if (root->Left_Child == NULL) {
            root->Left_Child = child;
        } else {
            insertNode(root->Left_Child, child);
        }
    } else {
        if (root->Right_Child == NULL) {
            root->Right_Child = child;
        } else {
            insertNode(root->Right_Child, child);
        }
    }
}

void destroyNode(BST_Node * root){
    if (root->Right_Child != NULL){
        destroyNode(root->Right_Child);
    }
    if (root->Left_Child != NULL){
        destroyNode(root->Left_Child);
    }
    root->Left_Child = NULL;
    root->Right_Child = NULL;
    free(root);
}

void postorder(BST_Node *root) {
    if (root == NULL) return;
    postorder(root->Left_Child);
    postorder(root->Right_Child);
    cout << root->data << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin >> num;
    BST_Node *root = createNode(num);
    while (cin >> num) {
        if (num == EOF) break;
        insertNode(root, createNode(num));
    }
    postorder(root);

}