#include "bits/stdc++.h"

using namespace std;

vector<pair<char, char>> binary_tree[26];
char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void dfs(int root ,int order) {
    if (root < 0 || root > 25) return;
    if (order == 0)cout << alpha[root];
    dfs(binary_tree[root].front().first - 'A',order);
    if (order == 1)cout << alpha[root];
    dfs(binary_tree[root].front().second - 'A',order);
    if (order == 2)cout << alpha[root];

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
    dfs(0,0);
    cout << '\n';
    dfs(0,1);
    cout << '\n';
    dfs(0,2);


}