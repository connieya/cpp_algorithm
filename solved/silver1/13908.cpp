#include "bits/stdc++.h"

using namespace std;

vector<char> V;
int ans = 0;

void dfs(int L, int n, string str) {
    if (L == n) {
        int len = str.size();
        int cnt = V.size();
        for (int i = 0; i < V.size(); ++i) {
            for (int j = 0; j < len; ++j) {
                if (str[j] == V[i]) {
                    cnt--;
                    break;
                }
            }
        }
        if (cnt == 0){
            ans++;
        }

        return;
    }
    for (int i = 0; i < 10; ++i) {
        char op = i + '0';
        dfs(L + 1, n, str + op);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        char num;
        cin >> num;
        V.push_back(num);
    }
    dfs(0, n, "");
    cout << ans;

}