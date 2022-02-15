#include "bits/stdc++.h"

using namespace std;

int gear[5][10];
bool check[5];
int direction[5];

void rotate_gear(int num, int r) {
    check[num] = true;
    direction[num] = r;
    if (num - 1 > 0 && gear[num][6] != gear[num - 1][2] && !check[num-1]) {
        r *= -1;
        rotate_gear(num - 1, r);
    }

    if (num + 1 < 5 && gear[num][2] != gear[num + 1][6] && !check[num+1]) {
        r *= -1;
        rotate_gear(num + 1, r);
    }
}

void rotate_s(int num) { // 시계 방향
    int tmp =gear[num][7];
    for (int i = 7; i > 0; --i) {
        gear[num][i] = gear[num][i-1];
    }
    gear[num][0] = tmp;
}
void rotate_rev(int num) { // 반시계 방향
    int tmp = gear[num][0];
    for (int i = 0; i < 7; ++i) {
        gear[num][i] = gear[num][i+1];
    }
    gear[num][7] = tmp;

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    int t, num, r, ans = 0;
    for (int i = 1; i <= 4; ++i) {
        cin >> input;
        for (int j = 0; j < input.size(); ++j) {
            gear[i][j] = input[j] - '0';
        }
    }
    cin >> t;
    while (t--) {
        cin >> num >> r;
        fill(check, check + 5, false);
        rotate_gear(num, r);
        for (int i = 1; i <= 4; ++i) {
            if (check[i]) {
                if (direction[i] == 1) {
                    rotate_s(i);
                } else if (direction[i] == -1) {
                    rotate_rev(i);
                }
            }
        }
    }
    ans += (gear[1][0] == 1) ? 1 : 0;
    ans += (gear[2][0] == 1) ? 2 : 0;
    ans += (gear[3][0] == 1) ? 4 : 0;
    ans += (gear[4][0] == 1) ? 8 : 0;
    cout << ans;
}