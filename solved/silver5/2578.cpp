#include "bits/stdc++.h"

using namespace std;

int bingo[6][6];
int row[6];
int column[6];
bool diagonal_l[6];
bool diagonal_r[6];

void solve(int num){
    bool flag = false;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            if (num == bingo[i][j]){
//                cout << i << ' ' << j << '\n';
                row[i]++;
                column[j]++;
                if (i==j) diagonal_l[i] = true;
                if (i+j == 6) diagonal_r[j] = true;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
}

int calcBingo() {
    int cnt = 0;
    bool a = true;
    bool b = true;
    for (int i = 1; i <= 5; ++i) {
        if (!diagonal_l[i]) a = false;
        if (!diagonal_r[i]) b= false;
    }
    cnt += a;
    cnt += b;
    for (int i = 1; i <=5 ; ++i) {
        cnt += (row[i] == 5) ? 1 : 0;
        cnt += (column[i] == 5) ? 1 : 0;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> bingo[i][j];
        }
    }
    int num;
    for (int i = 1; i <= 25; ++i) {
        cin >> num;
//        cout << num << '\n';
        solve(num);
        if (calcBingo() >=3){
            cout << i;
            exit(0);
        }
    }
}