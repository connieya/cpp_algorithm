#include "bits/stdc++.h"

using namespace std;

bool alpha[26];
int words[51];
int n;
int ans = -1;
void dfs(int L , int len , int start , int need) {
    if (L == len){
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((words[i] & ((1<< 26)-1 -need )) == 0){
                cnt++;
            }
        }
        if (cnt > ans){
            ans = cnt;
        }
        return;
    }

    for (int i = start; i < 26; ++i) {
        if (!alpha[i]){
            dfs(L+1,len,i+1 , need | (1 << i));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> k;
    if (k<5){
        cout << 0;
        return 0;
    }
    if (k==26){
        cout << n;
        return 0;
    }
    alpha[0] = alpha[2] = alpha['n'-'a'] = alpha['i'-'a'] = alpha['t'-'a'] = true;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c: s) {
            if (alpha[c-'a']) continue;
            words[i] |=  1 << (c-'a');
        }
    }
    k -= 5;
    dfs(0,k,1,0);
    cout << ans;
}