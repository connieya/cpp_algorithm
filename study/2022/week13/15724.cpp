#include "bits/stdc++.h"

using namespace std;

int territory[1025][1025];
int prefix_sum[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> territory[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += territory[j - 1][i];
            prefix_sum[j][i + 1] = sum;
        }
    }
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = 0;
        for (int i = y1; i <= y2; ++i) {
            answer += prefix_sum[x2][i] - prefix_sum[x1-1][i];
        }
        cout << answer << '\n';
    }

}