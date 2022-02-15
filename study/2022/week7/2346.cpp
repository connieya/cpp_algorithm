#include "bits/stdc++.h"

using namespace std;

typedef struct tagNode {
    int data;
    int index;
    struct tagNode *prevNode;
    struct tagNode *nextNode;
} Node;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n;
    Node *List = NULL;
    Node *tail = NULL;
    Node *cur = NULL;
    Node *del = NULL;
    for (int i = 1; i <= n; ++i) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        cin >> newNode->data;
        newNode->index = i;
        if (List == NULL) {
            List = newNode;
        } else {
            tail->nextNode = newNode;
            tail->nextNode->prevNode = tail;
        }
        tail = newNode;
    }
    List->prevNode = tail;
    tail->nextNode = List;
    cur = List;
    cout << cur->index << ' ';
    del = cur;
    cur->nextNode->prevNode = cur->prevNode;
    cur->prevNode->nextNode = cur->nextNode;
    n--;
    while (n){
        k = cur->data;
        if (k > 0){
            for (int i = k; i  > 0; --i) {
                cur = cur ->nextNode;
            }
            free(del);
            cur -> nextNode -> prevNode = cur->prevNode;
            cur -> prevNode -> nextNode= cur -> nextNode;
            del = cur;
        }else {
            for (int i = k; i < 0 ; ++i) {
                    cur = cur -> prevNode;
            }
            free(del);
            cur -> nextNode -> prevNode = cur->prevNode;
            cur -> prevNode -> nextNode= cur -> nextNode;
            del = cur;
        }
        n--;
        cout << cur->index << ' ';
    }
}