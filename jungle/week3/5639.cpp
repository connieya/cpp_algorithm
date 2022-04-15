#include "bits/stdc++.h"

using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
};

Node * insert(Node * node , int data){
    if (node == NULL){
        node = new Node();
        node->data = data;
        node->left = node->right = NULL;
    } else if (data <= node->data){
        node->left = insert(node->left , data);
    }else {
        node->right = insert(node->right , data);
    }
    return node;
}

void postorder(Node * node)
{
    if (node -> left != NULL)
        postorder(node->left);
    if (node->right != NULL)
        postorder(node->right);
    cout << node->data << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Node * root = NULL;
    int num;
    while (cin >> num) {
        if (num == EOF) break;
       root = insert(root,num);
    }
    postorder(root);
}