#include "bits/stdc++.h"

using namespace std;

int n, k;
vector<string> v;
bool check[27];
int ans = 0;

void dfs(int l, int start) {
    if (l == k) {
        int len = v.size();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            bool flag =false;
            for (char ch: v[i]) {
                if (!check[ch - 'a']) {
                    flag =true;
                    break;
                }
            }
            if(flag) continue;
            cnt++;
        }
        if(cnt > ans) ans = cnt;
        return;
    }

    for (int i = start; i <= 26; i++) {
        if (!check[i]) {
            check[i] = true;
            dfs(l + 1, i + 1);
            check[i] = false;
        };
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        v.push_back(str);
    }
    if (k < 5) {
        cout << 0;
        exit(0);
    }
    k-=5;
    check[0] = check[2] = check['n'-'a'] = check['t'-'a'] = check['i'-'a'] = true;
    dfs(0, 0);
    cout << ans;
}