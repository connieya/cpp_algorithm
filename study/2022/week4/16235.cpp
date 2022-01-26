#include "bits/stdc++.h"

using namespace std;

int add_energy[11][11];
int energy[11][11];
vector<int> tree[11][11];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> add_energy[i][j]; // 추가 되는 양분
            energy[i][j] = 5;// 처음 모든 양분은 5이다.
        }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][b].push_back(c);
    }
    while (k--) { // k년이 지난 뒤
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (tree[i][j].size() > 0) { // 나무가 심어져 있다면
                    vector<int> tmp;
                    sort(tree[i][j].begin(), tree[i][j].end());
                    int add = 0;
                    for (int l = 0; l < tree[i][j].size(); ++l) {
                        if (tree[i][j][l] <= energy[i][j]) { // 나무 나이보다 양분이 더 많으면
                            energy[i][j] -= tree[i][j][l];
                            tmp.push_back(tree[i][j][l] + 1);
                        } else { // 나무 나이가 양분보다 더 많으면 나무는 죽는다.
                            add += tree[i][j][l] / 2;
                        }
                    }
                    energy[i][j] += add; // 여름이 되어 봄에 죽은 나무가 양분이 되었다.
                    tree[i][j].clear();
                    tree[i][j] = tmp; // 양분을 먹고 나이가 1 증가한 나무 추가, 죽어서 양분이 된 나무 vector 에서 제거
                }
            }
        }
        // 가을이 되었다.
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (tree[i][j].size() > 0) { // 나무가 심어져 있다면
                    for (int l = 0; l < tree[i][j].size(); ++l) {
                        if (tree[i][j][l] % 5 == 0) { // 나무가 번식함
                            for (int i1 = 0; i1 < 8; ++i1) {
                                int nx = dx[i1] + i;
                                int ny = dy[i1] + j;
                                if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
                                tree[nx][ny].push_back(1);
                            }
                        }
                    }
                }
                // 겨울에 양분 추가
                energy[i][j] += add_energy[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans += tree[i][j].size();
        }
    }
    cout << ans;
}