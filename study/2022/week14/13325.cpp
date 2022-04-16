#include "bits/stdc++.h"

#define MAX (1 << 21)+1
using namespace std;

int arr[MAX];
int tree, result;

int dfs(int L) {
    if (L * 2 >= tree) {
        result += arr[L];
        return arr[L];
    }

    int leftNode = dfs(L * 2 + 1);
    int rightNode = dfs(L * 2 + 2);
    result += arr[L] + abs(leftNode - rightNode);
    return arr[L] + max(leftNode, rightNode);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    tree = 1 << (k + 1);
    for (int i = 1; i < tree - 1; ++i) {
        cin >> arr[i];
    }
    dfs(0);
    cout << result;
}