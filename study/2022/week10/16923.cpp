#include "bits/stdc++.h"

using namespace std;

int alpha[26];

char solve() {
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] == 0) return 'a'+i;
    }
    return 'A';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string S;
    char str[26];
    cin >> S;
    int len = S.length();
    for (int i = 0; i < len; ++i) {
        alpha[S[i]-'a']++;
        str[i] = S[i];
    }
    char res = solve();
    if (res == 'A'){
        if (next_permutation(str,str+26)){
            for (int i = 0; i < len; ++i) {
                if (str[i] == S[i]){
                    cout << str[i];
                }else {
                    cout << str[i];
                    break;
                }
            }
        } else {
            cout << -1;
        }
    }else {
        cout << S+res << '\n';
    }

}