#include "bits/stdc++.h"

using namespace std;

int from[] = {0, 0, 1, 1, 2, 2};
int to[] = {1, 2, 0, 2, 0, 1};
bool check[201][201];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cap[3];
    for (int i = 0; i < 3; ++i) {
        cin >> cap[i];
    }
    int sum = cap[2];
    check[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<int> ans;
    ans.push_back(cap[2]);
    while (!q.empty()) {
        int next[3] = {q.front().first, q.front().second, sum - q.front().first - q.front().second};
        q.pop();
        for (int i = 0; i < 6; ++i) {
            next[to[i]] += next[from[i]];
            next[from[i]] = 0;
            if (next[to[i]] >= cap[to[i]]) {
                next[from[i]] = next[to[i]] - cap[to[i]];
                next[to[i]] = cap[to[i]];
            }
            if (!check[next[0]][next[1]]) {
                check[next[0]][next[1]] = 1;
                q.push({next[0], next[1]});
                if (next[0] == 0) {
                    ans.push_back(next[2]);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto a: ans) {
        cout << a << ' ';
    }

}
