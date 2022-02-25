#include "bits/stdc++.h"

using namespace std;
unordered_map<char ,int> mp_s;
unordered_map<char ,int> mp_t;

void init(int len , string S) {
    for (int i = 0; i < len-1; ++i) {
        mp_s[S[i]]++;
    }
}

bool isAnagram() {
    return mp_s == mp_t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string S;
    string T;
    cin >> S  >> T;
    int len = T.size();
    int ans = 0;
    init(len,S);
    for (char ch: T) {
        mp_t[ch]++;
    }
    int lt = 0;
    int rt = len-1;
    while (rt < S.size()){
        mp_s[S[rt++]]++;
        if (isAnagram()) ans++;
        mp_s[S[lt]]--;
        if (mp_s[S[lt]] == 0) mp_s.erase(S[lt]);
        lt++;
    }
    cout << ans;
}