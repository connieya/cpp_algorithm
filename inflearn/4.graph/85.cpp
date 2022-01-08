#include "bits/stdc++.h"

using namespace std;

int arr[11];
int oper[4];
int n;
int MAX = -2147000, MIN = 2147000;

void dfs(int sum, int L) {
    if (L == n-1) {
        MAX = max(MAX, sum);
        MIN = min(MIN, sum);
        return;
    }

    if (oper[0] > 0) {
        oper[0]--;
        dfs(sum + arr[L], L + 1);
        oper[0]++;
    }
    if (oper[1] > 0) {
        oper[1]--;
        dfs(sum - arr[L], L + 1);
        oper[1]++;
    }
    if (oper[2] > 0) {
        oper[2]--;
        dfs(sum * arr[L], L + 1);
        oper[2]++;
    }
    if (oper[3] > 0) {
        oper[3]--;
        dfs(sum / arr[L], L + 1);
        oper[3]++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> oper[i];
    }
    dfs(arr[0], 1);
    cout << MAX << '\n' << MIN;

}