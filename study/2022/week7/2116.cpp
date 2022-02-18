#include "bits/stdc++.h"

using namespace std;

int dice[10001][7];
int n;
void solve(int index) {
    // index 는 1번 주사위에 윗면의 값
    int top = 0;
    int bottom = 0;
    int ans = 0;
    if (index == 1){
        top = 1;
        bottom = 6;
    } else if (index == 2) {
        top = 2;
        bottom = 4;
    }else if (index == 3) {
        top = 3;
        bottom = 5;
    }else if (index == 4) {
        top = 4;
        bottom = 2;
    }else if (index == 5) {
        top = 5;
        bottom = 3;
    }else {
        top = 6;
        bottom =1;
    }
    // index 의 값은 1~6번 으로  index의 값은 1번 주사위의 윗면의 값을 가리키는 index
    for (int j = 1; j <=n; ++j) {
        for (int k = 1; k <= 6; ++k) {
             top = dice[j][top]; // j번째 윗면의 값
             bottom = dice[j][bottom]; // j번째 아랫면 값
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            cin >> dice[i][j];
        }
    }
    for (int index = 1; index <= 6; ++index) {

    }
}