#include "bits/stdc++.h"

using namespace std;

int board[501][501];
int ans[501][501];
int n;
void solve1(int degree){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = board[i][j];
        }
    }
    if(degree == 45){
        for (int i = 0; i < n; ++i) {
            ans[i][n/2] = board[i][i];
        }
        for (int i = 0; i < n; ++i) {
            ans[i][n-1-i] = board[i][n/2];
        }
        for (int i = 0; i < n; ++i) {
            ans[n/2][i] = board[n-1-i][i];
        }
        for (int i = 0; i < n; ++i) {
            ans[i][i] = board[n/2][i];
        }

    }else if(degree == 90) {

    }else if(degree == 135){

    }else {

    }
}

void solve2(int degree) {
    if(degree == -45){

    }else if(degree == -90){

    }else if(degree == -135){

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int degree;
        cin >> n >> degree;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        degree = degree > 180 ? degree-360 : degree;
        // 45 ~ 360 까지 그냥 노가다를 해야 하나?
        if(degree > 0){
            solve1(degree);
        }else {
            solve2(degree);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}