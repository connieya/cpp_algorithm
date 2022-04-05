#include "bits/stdc++.h"

using namespace std;

vector<string> str;
int ans = -1;
bool alpha[26];

bool isReadableWord(string s) {
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (!alpha[s[i]-'a']) return false;
    }
    return true;
}

void dfs(int L , int len , int start){
    if (L == len){
        int cnt = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (isReadableWord(str[i])){
                cnt++;
            }
        }
        if (cnt > ans) {
            ans = cnt;
        }
        return;
    }

    for (int i = start; i < 26; ++i) {
        if (!alpha[i]){
            alpha[i] = true;
            dfs(L+1, len ,i+1);
            alpha[i] = false;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    string s;
    cin >> n >> k;
    if(k < 5) {
        cout << 0;
        return 0;
    }
    if (k == 26) {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> s;
        str.push_back(s);
    }
    k -= 5;
    alpha[0] = alpha[2] = alpha['n'-'a'] = alpha['t'-'a'] = alpha['i'-'a'] = true;
    dfs(0,k,1);
    cout << ans;

}