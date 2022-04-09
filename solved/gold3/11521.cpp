#include "bits/stdc++.h"

using namespace std;

char grid[9][9];
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
bool visited[9][9];
vector<string> words;

bool dfs(int L, const string &word, int len, int x, int y, int n) {
    if (L == len) {
        return true;
    }
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (word[L] == 'q' && word[L] == grid[nx][ny] && !visited[nx][ny]){
            visited[nx][ny] = true;
            if (dfs(L + 2, word, len, nx, ny, n)) return true;
            visited[nx][ny] = false;
        }else if (word[L] == grid[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny] = true;
            if (dfs(L + 1, word, len, nx, ny, n)) return true;
            visited[nx][ny] = false;
        }
    }
    return false;

}

bool playBoggleGame(string word, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (word[0] == grid[i][j]) {
                if (word[0] == 'q') {
                    if (word[1] == 'u') {
                        if (dfs(2, word, word.length(), i, j, n)) return true;
                    }

                } else {
                    if (dfs(1, word, word.length(), i, j, n)) return true;
                }

            }
        }
    }
    return false;
}

void init(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }
}

vector<string> solve(int n) {
    int len = words.size();
    vector<string> answer;
    for (int i = 0; i < len; ++i) {
        init(n);
        if (playBoggleGame(words[i], n)) {
            answer.push_back(words[i]);
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, size;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    while (1) {
        cin >> size;
        if (!size) break;
        for (int i = 0; i < size; ++i) {
            cin >> grid[i];
        }
        vector<string> ans = solve(size);
        sort(ans.begin(), ans.end());
        for (string s: ans) {
            cout << s << '\n';
        }
        cout << "-" << '\n';

    }

}