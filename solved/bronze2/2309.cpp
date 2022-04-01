#include "bits/stdc++.h"

using namespace std;

int arr[10];
int temp[8];

void solve() {
    for (int i = 0; i < 7; ++i) {
        cout << temp[i] << '\n';
    }
    exit(0);
}

void dfs(int L, int start) {
    if (L == 7) {
        int sum = 0;
        for (int i = 0; i < 7; ++i) {
            sum += temp[i];
        }
        if (sum == 100) {
            solve();
        }
        return;
    }

    for (int i = start; i < 10; ++i) {
        temp[L] = arr[i];
        dfs(L + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + 9);
    dfs(0, 0);

}