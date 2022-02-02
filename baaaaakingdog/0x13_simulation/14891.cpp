#include "bits/stdc++.h"

using namespace std;

int gear[6][9];

void rotate(int num) { // 시계 방향
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t , ans =0;
    for (int i = 1; i <= 4; ++i) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 8; ++j) {
            gear[i][j] = tmp[j]-'0';
        }
    }
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int num , r;
        cin >> num >> r;
        if(gear[num][2] != gear[num+1][6]){
            (r == 1) ? rotate_rev(num+1) : rotate(num+1);
        }
        if (gear[num][6] != gear[num-1][2]) {
            (r == 1) ? rotate_rev(num-1) : rotate(num-1);
        }
        if (r== 1){
            rotate(num);
        }else {
            rotate_rev(num);
        }

    }
    ans += (gear[1][0] ==1) ? 1 : 0;
    ans += (gear[2][0] ==1) ? 2 : 0;
    ans += (gear[3][0] ==1) ? 4 : 0;
    ans += (gear[4][0] ==1) ? 8 : 0;
    cout << ans;
}