#include "bits/stdc++.h"

#define INF 20001

using namespace std;

int a[INF];
int b[INF];
int c[INF];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, min_value;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int i = n - 1;
    int j = n - 1;
    int k = n - 1;
    while (i > 0 && j > 0 && k > 0) {
        if (a[i] == b[j] && b[j] == c[k]) {
            cout << a[i];
            exit(0);
        }
        min_value = min(a[i], min(b[j], c[k]));
        if (min_value != a[i]) i--;
        if (min_value != b[j]) j--;
        if (min_value != c[k]) k--;
    }
    cout << -1;


}