#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int n, q, a, b, c;
ll arr[100001];
ll mx = 0, sum = 0;
void add() {
    arr[c] += b;
    if (c <= n) {
        sum += arr[c];
        if (arr[c] > mx) {
            mx = arr[c];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            add();
        } else {
            if (arr[n + 1] + b > mx && (arr[n + 1] + b - 1) * n >= sum + c) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}