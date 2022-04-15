#include <iostream>
#include "stdlib.h"

using namespace std;

typedef struct Node {
    char Data;
    Node *left;
    Node *right;
} Node;

Node *createNode(char data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Data = data;
    return newNode;
}

void preorder(Node *root) {
    if (root == NULL) {
        return;
    }

    cout << root->Data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->Data;
    inorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->Data;
}

void destroyTree(Node *node) {
    if (node->right != NULL) {
        destroyTree(node->right);
    }
    if (node->left != NULL) {
        destroyTree(node->left);
    }
    node->left = NULL;
    node->right = NULL;
    free(node);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    char p, l, r;
    Node *tree[26];
    cin >> t;
    for (int i = 0; i < t; ++i) {
        tree[i] = createNode((char) 'A' + i);
    }
    for (int i = 0; i < t; ++i) {
        cin >> p >> l >> r;
        Node *parent = tree[p - 'A'];
        if (l != '.') {
            Node *left_child = tree[l - 'A'];
            parent->left = left_child;
        }
        if (r != '.') {
            Node *right_child = tree[r - 'A'];
            parent->right = right_child;
        }
    }
    preorder(tree[0]);
    cout << '\n';
    inorder(tree[0]);
    cout << '\n';
    postorder(tree[0]);
    destroyTree(tree[0]);
}