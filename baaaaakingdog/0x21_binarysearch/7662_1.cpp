#include "bits/stdc++.h"

using namespace std;

typedef struct BSNode{
    struct BSNode * left;
    struct BSNode * right;

    int data;
} Node;

Node * createNode(int data) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> data = data;
    return newNode;
}

void destroyNode(Node * node){
    free(node);
}

void destroyTree(Node * tree) {
    if (tree ->right != NULL){
        destroyTree(tree->right);
    }
    if (tree->right != NULL){
        destroyTree(tree->right);
    }
    tree ->left =NULL;
    tree -> right = NULL;
    destroyNode(tree);
}

Node * searchMinNode(Node * tree)
{
    if (tree == NULL){
        return NULL;
    }
    if (tree->left == NULL)
        return tree;
    else
        return searchMinNode(tree->left);
}

Node * searchMaxNode(Node * tree)
{
    if (tree == NULL){
        return NULL;
    }
    if (tree->right == NULL)
        return tree;
    else
        return searchMaxNode(tree->right);
}

void insertNode(Node* tree , Node * child)
{
    if (tree == NULL) {
        tree = child;
        return;
    }

    if (tree ->data <= child->data){
        if (tree->right == NULL){
            tree->right = child;
        }else {
            insertNode(tree->right,child);
        }
    } else {
        if (tree-> left == NULL) {
            tree -> left = child;
        }else {
            insertNode(tree->left, child);
        }
    }
}

Node * removeNode(Node * tree , Node * parent , int target)
{
    Node  * removed = NULL;
    if (tree == NULL)
        return NULL;

    if (tree->data > target) {
        removed = removeNode(tree->right , tree,target);
    } else if (tree->data < target){
        removed = removeNode(tree->left ,tree, target);
    } else {
        removed = tree;
        if (tree->left == NULL && tree->right == NULL){

            if (parent->left == tree) {
                parent->left = NULL;
            }else {
                parent->right= NULL;
            }

        }else {

            if (tree->left != NULL && tree->right != NULL) {

                Node * minNode = searchMinNode(tree->right);
                minNode = removeNode(tree , NULL , minNode->data);
                tree->data = minNode->data;

            } else {
                Node  * temp = NULL;
                if (tree->left != NULL){
                    temp = tree->left;
                }else {
                    temp = tree -> right;
                }

                if (parent->left == tree) {
                    parent->left = temp;
                }else {
                    parent -> right = temp;
                }
            }
        }
    }
    return removed;
}

bool isEmpty(Node * root){
    return root->left == NULL && root->right == NULL;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t , n  , num;
    char command;
    cin >> t;
    while (t--) {
        cin >> n;
        Node * root = NULL;
        for (int i = 0; i < n; ++i) {
            cin >> command >> num;
            if (command == 'I') {
                insertNode(root , createNode(num));
            }else {
                if (num == 1){
                    Node *MAX = searchMaxNode(root);
                    if (MAX != NULL){
                        removeNode(root , NULL , MAX->data);
                    }
                }else {
                    Node *MIN = searchMinNode(root);
                    if (MIN != NULL) {
                        removeNode(root,NULL,MIN->data);
                    }
                }
            }
        }
        if (isEmpty(root)){
            cout << "EMPTY" << '\n';
        }else {
            cout << searchMaxNode(root)->data << ' ' << searchMinNode(root)-> data <<'\n';
        }
    }
}