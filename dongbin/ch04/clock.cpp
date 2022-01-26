#include "bits/stdc++.h"

using namespace std;


int h, cnt;

bool check(int hour, int minute, int second) {
    if (hour % 10 == 3 || minute % 10 == 3 || minute / 10 == 3 || second % 10 == 3 || second / 10 == 3) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h;
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j < 60; ++j) {
            for (int k = 0; k < 60; ++k) {
                if (check(i, j, k)) {
                    cnt++;
                }
            }

        }
    }
    cout << cnt << '\n';
}