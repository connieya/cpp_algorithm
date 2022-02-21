#include "bits/stdc++.h"

using namespace std;

int dice[10001][7];
int n;
int front[7];

int solve(int sum , int top,int bottom){
    int std = top;
    for (int i = 2; i <=n; ++i) {
        int MAX = 0;
        for (int j = 1; j <= 6; ++j) {
            if (dice[i][j] == std){
                bottom = top;
                top = dice[i][front[j]];
                break;
            }
        }
        for (int j = 1; j <= 6; ++j) {
            if (dice[i][j] != bottom && dice[i][j] != top){
                MAX = max(MAX , dice[i][j]);
            }
        }
        sum += MAX;
        std = top;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            cin >> dice[i][j];
        }
    }
    front[1] = 6, front[2] = 4, front[3] = 5;
    front[4] = 2, front[5] = 3, front[6] = 1;
    int ans = 0;
    for (int i = 1; i <= 6; ++i) {
        int top = dice[1][i];
        int bottom = dice[1][front[i]];
        int sum = 0;
        int MAX = 0;
        for (int j = 1; j <= 6; ++j) {
            if (dice[1][j] != top && dice[1][j] != bottom) {
                MAX = max(MAX, dice[1][j]);
            }
        }
        sum += MAX;
        ans = max(solve(sum,top,bottom),ans);
    }
    cout << ans;
}