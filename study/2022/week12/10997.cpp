#include "bits/stdc++.h"

using namespace std;

char star[500][500];

void func(int y,int x ,int depth){
    if (depth == 2) {
        for (int i = 0; i < 5; ++i) {
            star[y][x+i] = '*';
            star[y+6][x+i] = '*';
        }

        for (int i = 1; i < 6; ++i) {
            star[y+i][x] = '*';
        }

        for (int i = 2; i < 6; ++i) {
            star[y+i][x+4] = '*';
            if (i>4){
                continue;
            }
            star[y+i][x+2] = '*';
        }
        star[y+2][x+3] = '*';
        return;
    }
    for (int i = 0; i < 4 * (depth - 1) + 1; ++i) {
        star[y][x+i] = '*';
        star[y+7+4*(depth-2)-1][x+i] = '*';
    }
    for (int i = 1; i < 7+4*(depth-2); ++i) {
        star[y+i][x] = '*';
        if (i==1){
            continue;
        }
        star[y+i][x+4*(depth-1)] = '*';
    }
    star[y+2][x+4*(depth-1)-1] = '*';
    func(y+2,x+2,depth-1);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "*";
        return 0;
    }
    func(0,0,n);
    for (int i = 0; i < 7 + 4 * (n - 2); ++i) {
        if (i == 1) {
            cout << "*\n";
            continue;
        }
        for (int j = 0; j < 4 * (n - 1) + 1; ++j) {
            char c = star[i][j] == '*' ? '*' : ' ';
            cout << c;
        }
        cout << '\n';
    }
}