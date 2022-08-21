#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v = {1, 1, 1, 2, 3, 3, 4, 4, 4, 4, 5, 4, 4, 3, 2, 1};
    for (int l = 0, r = 0; ++r < v.size(); l = r) {
        if (v[l] == v[r]) {
            while (++r < v.size()) {
                if (v[l] != v[r]) {
                    v[++l] = v[r];
                }
            }
            break;
        }
    }
    for (auto &i: v) {
        cout << i << ' ';
    }
    cout << '\n';
}