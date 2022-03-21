#include "bits/stdc++.h"

using namespace std;
int dp[101][101][101];

int func_w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return func_w(20, 20, 20);
    if (a < b && b < c) {
        if (dp[a][b][c] > 0) return dp[a][b][c];
        return dp[a][b][c] = func_w(a, b, c - 1) + func_w(a, b - 1, c - 1) - func_w(a, b - 1, c);
    }
    if (dp[a][b][c] > 0) return dp[a][b][c];
    return dp[a][b][c] =
            func_w(a - 1, b, c) + func_w(a - 1, b - 1, c)
            + func_w(a - 1, b, c - 1)- func_w(a - 1, b - 1, c - 1);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w("<<a<<", "<<b<<", "<<c<<") = "<<func_w(a, b, c) << '\n';
    }
}