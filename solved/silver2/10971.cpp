#include "bits/stdc++.h"

using namespace std;

int arr[11][11];
vector<int> V;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 21470000;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        V.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }
    do {
        int len = V.size();
        int sum = 0;
        bool flag = false;
        for (int i = 0; i < len - 1; ++i) {
            if (arr[V[i]][V[i + 1]] == 0) {
                flag = true;
                break;
            }
            sum += arr[V[i]][V[i + 1]];
        }
        if (!flag && arr[V[len-1]][V[0]] != 0) {
            sum += arr[V[len - 1]][V[0]];
            if (ans > sum) {
                ans = sum;
            }
        }
    } while (next_permutation(V.begin(), V.end()));

    cout << ans;
}