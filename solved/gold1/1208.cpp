#include "bits/stdc++.h"

using namespace std;

int a[21];
int b[21];
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n / 2; ++i) {
        cin >> a[i];
    }
    int m = n - n / 2;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    n = n / 2;
    vector<int> first, second;
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) sum += a[j];
        }
        first.push_back(sum);
    }
    for (int i = 0; i < (1 << m); ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) sum += b[j];
        }
        second.push_back(sum);
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    reverse(second.begin(), second.end());
    int lt = 0, rt = 0;
    ll ans = 0;
    while (lt < first.size() && rt < second.size()) {
        if (first[lt] + second[rt] == s) {
            ll c1 = 1, c2 = 1;
            lt++;
            rt++;
            while (lt < first.size() && first[lt] == first[lt - 1]) {
                lt++;
                c1++;
            }
            while (rt < second.size() && second[rt] == second[rt - 1]) {
                rt++;
                c2++;
            }
            ans += c1 * c2;

        } else if (first[lt] + second[rt] > s) {
            rt++;
        } else {
            lt++;
        }
    }

    if (s == 0) ans--;
    cout << ans;
}