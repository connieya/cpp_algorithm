#include "bits/stdc++.h"

using namespace std;

int board[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    int min_height = 257;
    int max_height = -1;
    int least_time = INT_MAX;
    int res;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            min_height = min(min_height, board[i][j]);
            max_height = max(max_height, board[i][j]);
        }
    }
    for (int height = min_height; height <= max_height; ++height) {
        int time = 0;
        int inventory = k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (height > board[i][j]) {
                    time += (height - board[i][j]);
                    inventory -= (height - board[i][j]);
                } else if (height < board[i][j]) {
                    time += (board[i][j] - height) * 2;
                    inventory += (board[i][j]-height);
                }
            }
        }
        if (inventory < 0) continue;
        if (time < least_time) {
            least_time = time;
            res = height;
        }
        else if (time == least_time){
            res = max(res, height);
        }
    }
    cout << least_time << ' ' << res;
}