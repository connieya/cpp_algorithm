#include "bits/stdc++.h"

#define MAX 1001
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

ull subject[MAX];
ull student[MAX];
ull s = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, t;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            subject[i] |= (1ll << t);
        }

    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        s = 0;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            student[i] |= (1ll << t);
        }
    }
    for (int i = 0; i < m; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if ((subject[j] & student[i]) == subject[j]){
                ans++;
            }
        }
        cout << ans << '\n';
    }
}