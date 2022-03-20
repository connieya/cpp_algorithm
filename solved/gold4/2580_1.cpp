#include "bits/stdc++.h"

using namespace std;

bool row[9][10];
bool column[9][10];
bool group[9][10];
int arr[10][10];

int find_group(int x, int y) {
    return x / 3 * 3 + y / 3;
}

void print() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int L) {
    int x = L/9;
    int y = L%9;
    int g = find_group(x,y);

    if (L == 81) {
        print();
        exit(0);
    }

    if (arr[x][y] == 0){
        for (int i = 1; i <= 9; ++i) {
            if (!row[x][i] && !column[y][i] && !group[g][i]){
                row[x][i] = column[y][i] = group[g][i] = true;
                arr[x][y] = i;
                dfs(L+1);
                arr[x][y] = 0;
                row[x][i] = column[y][i] = group[g][i] = false;
            }
        }
    }else {
        dfs(L+1);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num;
            cin >> num;
            arr[i][j] = num;
            if (num != 0) {
                int idx = find_group(i, j);
                row[i][num] = column[j][num] = group[idx][num] = true;
            }
        }
    }
    dfs(0);
}