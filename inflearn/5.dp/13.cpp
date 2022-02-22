#include "bits/stdc++.h"

#define INF 21470000

using namespace std;

int arr[51][51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            arr[i][j] = INF;
        }
    }
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a + b == -2) break;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    vector<int> ans;
    int MIN = INF;
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == INF) continue;
            tmp = max(tmp, arr[i][j]);
        }
        if (tmp < MIN) {
            MIN = tmp;
            ans.clear();
            ans.push_back(i);
        } else if (tmp == MIN) {
            ans.push_back(i);
        }
    }
    cout << MIN << ' ' << ans.size() << '\n';
    for (int a: ans) {
        cout << a << ' ';
    }

}