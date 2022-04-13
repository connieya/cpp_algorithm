#include "bits/stdc++.h"

using namespace std;

char chess[8][8];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        cin >> chess[i];
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (chess[i][j] == '.') continue;
            if (i % 2 == 0 && j % 2 == 0) {
                ans++;
            } else if (i % 2 && j % 2) {
                ans++;
            }
        }
    }
    cout << ans;


}