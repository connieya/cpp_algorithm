#include "bits/stdc++.h"

using namespace std;

int ining[51][10];
int n;
int order[10];
bool visited[10];
int answer = 0;

void playGame() {
    int score = 0;
    int start_player = 1;
    int base_state[4];
    for (int i = 1; i <= n; ++i) {
        int out_count = 0;
        bool next_ining = false;
        memset(base_state, 0, sizeof(base_state));
        while (1) {
            for (int j = start_player; j <= 9; ++j) {
                int player = ining[i][order[j]];
                if (player == 0) {
                    out_count++;
                } else if (player == 1) {
                    score += base_state[3];
                    base_state[3] = base_state[2] ? 1 : 0;
                    base_state[2] = base_state[1] ? 1 : 0;
                    base_state[1] = 1;
                } else if (player == 2) {
                    score += base_state[3];
                    score += base_state[2];
                    base_state[3] = base_state[1] ? 1 : 0;
                    base_state[2] = 1;
                    base_state[1] = 0;
                } else if (player == 3) {
                    score += base_state[3];
                    score += base_state[2];
                    score += base_state[1];
                    base_state[3] = 1;
                    base_state[2] = 0;
                    base_state[1] = 0;
                } else if (player == 4) {
                    score += base_state[3];
                    score += base_state[2];
                    score += base_state[1];
                    score++;
                    base_state[3] = base_state[2] = base_state[1] = 0;
                }

                if (out_count == 3) {
                    next_ining = true;
                    start_player = j + 1;
                    if (start_player == 10) {
                        start_player = 1;
                    }
                    break;
                }
            }
            if (next_ining) break;
            start_player = 1;
        }
    }
    answer = max(answer, score);
}

void dfs(int cnt) {
    if (cnt == 10) {
        playGame();
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        order[i] = cnt;
        dfs(cnt + 1);
        visited[i] = false;
    }
}

void solve() {
    vector<int> perm(10);
    for (int i = 1; i <= 9; ++i) {
        perm[i] = i;
    }
    do {
        for (int i = 1; i <= 3; ++i) {
            order[i] = perm[i];
        }
        order[4] = 1;
        for (int i = 5; i <=9 ; ++i) {
            order[i] = perm[i];
        }
        playGame();
    } while (next_permutation(perm.begin()+1,perm.begin()+10));
//    order[4] = 1;
//    visited[4] = true;
//    dfs(2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> ining[i][j];
        }
    }
    solve();
    cout << answer;
}