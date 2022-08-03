#include "bits/stdc++.h"

using namespace std;

vector<string> ans;
string mn, mx;
vector<char> v;
int n;

void dfs(int l, string str) {
    if (l == n + 1) {
        if (mx.empty()) {
            mx = str; mn = str;
        }
        else {
            mx = max(mx, str);
            mn = min(mn, str);
        }
        return;
    }

    for (char i = '0'; i <= '9'; ++i) {
        if (str.find(i) != string::npos) continue; // 포함 되어 있니??
        if (l == 0) dfs(l + 1, str + i);
        else {
            if (v[l - 1] == '>' && str.back() > i) dfs(l + 1, str + i);
            else if (v[l - 1] == '<' && str.back() < i) dfs(l + 1, str + i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char ch;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        v.push_back(ch);
    }
    dfs(0, "");
    cout << mx << '\n' << mn;
}