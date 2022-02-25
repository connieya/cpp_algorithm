#include "bits/stdc++.h"

using namespace std;

int alpha_s[26];
int alpha_t[26];

void init(int len , string S) {
    for (int i = 0; i < len; ++i) {
        alpha_s[S[i]-'a']++;
    }
}

bool isAnagram() {
    for (int i = 0; i < 26; ++i) {
        if (alpha_s[i] != alpha_t[i]){
            return false;
        }
    }
    return true;
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
        alpha_t[ch-'a']++;
    }
    if (isAnagram()) ans++;
    int lt = 0;
    int rt = len-1;
    while (rt < S.size()-1){
        alpha_s[S[lt++]-'a']--;
        alpha_s[S[++rt]-'a']++;
        if (isAnagram()){
            ans++;
        }
    }
    cout << ans;
}