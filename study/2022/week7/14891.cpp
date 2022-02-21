#include "bits/stdc++.h"

using namespace std;

int gear[5][10];
bool checked[5];
bool visited[5];
int direction[5];

void dfs(int num, int dir) {

    if (num - 1 >= 0 && gear[num][6] != gear[num - 1][2] && !checked[num - 1]) {
        checked[num - 1] = true;
        visited[num - 1] = true;
        direction[num - 1] = dir * -1;
        dfs(num - 1, dir * -1);
    }

    if (num + 1 < 4 && gear[num][2] != gear[num + 1][6] && !checked[num + 1]) {
        checked[num + 1] = true;
        visited[num + 1] = true;
        direction[num + 1] = dir * -1;
        dfs(num + 1, dir * -1);
    }
}

void rotate(int num) {
    int temp = gear[num][7];
    for (int i = 7; i > 0; --i) {
        gear[num][i] = gear[num][i - 1];
    }
    gear[num][0] = temp;
}

void rotate_rev(int num) {
    int temp = gear[num][0];
    for (int i = 0; i < 7; ++i) {
        gear[num][i] = gear[num][i + 1];
    }
    gear[num][7] = temp;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    for (int i = 0; i < 4; ++i) {
        cin >> input;
        for (int j = 0; j < 8; ++j) {
            gear[i][j] = input[j] - '0';
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int num, dir;
        cin >> num >> dir;
        fill(visited, visited + 5, false);
        fill(direction, direction + 5, -1);
        fill(checked, checked + 5, false);
        checked[num - 1] = true;
        visited[num - 1] = true;
        direction[num - 1] = dir;
        dfs(num - 1, dir);
        for (int i = 0; i < 4; ++i) {
            if (visited[i]) {
                if (direction[i] == 1) {
                    rotate(i);
                } else if (direction[i] == -1) {
                    rotate_rev(i);
                }
            }
        }
    }
    int ans = 0;
    ans += (gear[0][0] == 1) ? 1 : 0;
    ans += (gear[1][0] == 1) ? 2 : 0;
    ans += (gear[2][0] == 1) ? 4 : 0;
    ans += (gear[3][0] == 1) ? 8 : 0;
    cout << ans;
}