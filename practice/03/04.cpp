#include "bits/stdc++.h"

using namespace std;

int sudoku[10][10];
bool rows[9][10]; // 각 행에 1,2,3,4,5,6,7,8,9 가 있는지 확인
bool columns[9][10]; // 각 열에 1,2,3,4,5,6,7,8,9 가 있는지 확인
bool groups[9][10]; // 각 그룹에 1,2,3,4,5,6,7,8,9가 있는지 확인 , 그룹은 0 ~ 8 그룹까지 있음
vector<pair<int, int>> V;


int find_group(int x, int y) {
    return x / 3 * 3 + y / 3;
}

void dfs(int L, int len) {
    if (L == len) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    int r = V[L].first;
    int c = V[L].second;
    int g = find_group(r, c);
    for (int i = 1; i <= 9; ++i) {
        if (!rows[r][i] && !columns[c][i] && !groups[g][i]) {
            sudoku[r][c] = i;
            rows[r][i] = columns[c][i] = groups[g][i] = true;
            dfs(L + 1, len);
            rows[r][i] = columns[c][i] = groups[g][i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
            int g = find_group(i, j);
            if (sudoku[i][j] == 0) {
                V.push_back({i, j});
            } else {
                rows[i][sudoku[i][j]] = columns[j][sudoku[i][j]] = groups[g][sudoku[i][j]] = true;
            }
        }
    }
    int len = V.size();
    dfs(0, len);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sudoku[i][j] <<' ';
        }
        cout << '\n';
    }

}