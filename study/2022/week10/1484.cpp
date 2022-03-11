#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long a = 1, b = 1;
    bool flag = false;
    vector<int> ans;
    while (1) {
        if (a * a - b * b < n) {
            a++;
        } else {
            if (a * a - b * b == n) {
                flag = true;
                cout << a << '\n';
            }
            if (a-b == 1) break;
            b++;
        }
    }
    if (!flag) {
        cout << -1;
    }

}