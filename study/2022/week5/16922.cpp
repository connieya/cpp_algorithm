#include "bits/stdc++.h"

using namespace std;

bool check[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            for (int k = 0; k <= n - i - j; ++k) {
                int value = i * 1 + j * 5 + k * 10 + (n - i - j - k) * 50;
                if (!check[value]) {
                    check[value] = true;
                    ans++;
                }

            }
        }
    }
    cout << ans;
}