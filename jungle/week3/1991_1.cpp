#include "bits/stdc++.h"

using namespace std;

vector<pair<char, char>> binary_tree[26];
string alpha[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                  "U",
                  "V", "W", "X", "Y", "Z"};

string preorder(int root) {
    if (root < 0 || root > 25) return "";
    return  alpha[root] + preorder(binary_tree[root].front().first - 'A') +
           preorder(binary_tree[root].front().second - 'A');

}

string inorder(int root) {
    if (root < 0 || root > 25) return "";
    return inorder(binary_tree[root].front().first - 'A') + alpha[root] +
           inorder(binary_tree[root].front().second - 'A');

}

string postorder(int root) {
    if (root < 0 || root > 25) return "";
    return postorder(binary_tree[root].front().first - 'A') + postorder(binary_tree[root].front().second - 'A') +
           alpha[root];

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        char root, left, right;
        cin >> root >> left >> right;
        binary_tree[root - 'A'].push_back({left, right});
    }
    cout << preorder(0) << '\n';
    cout << inorder(0) << '\n';
    cout << postorder(0) << '\n';
}