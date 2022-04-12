#include "bits/stdc++.h"

#define MAX (1 << 21)+1
using namespace std;

int arr[MAX];

int dfs(int L, int k, int sum) {
    if (L >= k) {
        return 0;
    }

    int lsum = dfs(L * 2, k, sum)+arr[L*2];
    int rsum = dfs(L * 2 + 1, k, sum)+arr[L*2+1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    int tree = 1 << (k + 1);
    for (int i = 2; i < tree; ++i) {
        cin >> arr[i];
    }
    dfs(1, tree, 0);
}