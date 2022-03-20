#include "bits/stdc++.h"

using namespace std;

int calc_targetPoint(int x1, int y1, int r1, int x2, int y2, int r2) {
    if (x1 == x2 && y1 == y2 && r1 == r2) {
        return -1;
    }
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
        return 0;
    }

    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 - r2) * (r1 - r2)) {
        return 0;
    }

    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == (r1 - r2) * (r1 - r2)) {
        return 1;
    }

    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == (r1 + r2) * (r1 + r2)) {
        return 1;
    }

    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << calc_targetPoint(x1, y1, r1, x2, y2, r2) << '\n';
    }
}