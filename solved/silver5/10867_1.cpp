#include "bits/stdc++.h"

using namespace std;

bool checked[2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        checked[num + 1000] = true;
    }
    for (int i = 0; i <= 2000; ++i) {
        if (checked[i]) {
            cout << i - 1000 << ' ';
        }
    }
}