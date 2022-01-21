#include "bits/stdc++.h"

using namespace std;

int leftChild[27];
int rightChild[27];

void preOrder(int root) {
    if (root == 0) return;

    cout << char(root+'A'-1);
    preOrder(leftChild[root]);
    preOrder(rightChild[root]);
}

void InOrder(int root) {
    if (root == 0) return;

    InOrder(leftChild[root]);
    cout << char(root+'A'-1);
    InOrder(rightChild[root]);
}


void PostOrder(int root) {
    if (root == 0) return;

    PostOrder(leftChild[root]);
    PostOrder(rightChild[root]);
    cout << char(root+'A'-1);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        char root, lc, rc;
        cin >> root >> lc >> rc;
        if (lc != '.') leftChild[root-'A'+1] = lc-'A'+1;
        if (rc != '.') rightChild[root-'A'+1] = rc-'A'+1;
    }
    preOrder(1);
    cout << '\n';
    InOrder(1);
    cout << '\n';
    PostOrder(1);
    cout << '\n';
}