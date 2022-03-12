#include "bits/stdc++.h"

using namespace std;

int n, ans = 21470000;
int arr[11][11];
bool visited[11][11];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
        if (visited[nx][ny]) return false;
    }
    return true;
}

int calcValue(int x, int y) {
    int sum = arr[x][y];
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        sum += arr[nx][ny];
        visited[nx][ny] = true;
    }
    return sum;
}

void init(int x, int y) {
    visited[x][y] = false;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = false;
    }
}

void dfs(int sum, int L) {
    if (L == 3) {
        if (ans > sum) {
            ans = sum;
        }
        return;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (isValid(i, j)) {
                dfs(sum + calcValue(i, j), L + 1);
                init(i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0);
    cout << ans;
}