#include "bits/stdc++.h"

using namespace std;

struct line {
    int start, end;
};

int solve(line a, line b) {
    if (a.start > b.start) {
        line tmp = a;
        a = b;
        b = tmp;
    }
    if (a.end < b.start) return 0;
    else if (a.end == b.start) return 1;
    return 2;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    line a_x, a_y, b_x, b_y;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a_x.start = x1, a_x.end = x2, a_y.start = y1, a_y.end = y2;
    cin >> x1 >> y1 >> x2 >> y2;
    b_x.start = x1, b_x.end = x2, b_y.start = y1, b_y.end = y2;
    int res_x = solve(a_x, b_x), res_y = solve(a_y, b_y);
    if (res_x == 2 && res_y == 2) cout << "FACE";
    else if ((res_x == 1 && res_y == 2) || (res_x == 2 && res_y == 1)) cout << "LINE";
    else if (res_x == 1 && res_y == 1) cout << "POINT";
    else cout << "NULL";
}