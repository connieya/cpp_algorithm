#include "bits/stdc++.h"

using namespace std;

int alpha[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> ans;
    int n;
    char ch;
    string str;
    cin >> n >> ch;
    ch = toupper(ch);
    for (int i = 0; i < n; ++i) {
        cin >> str;
        fill(alpha,alpha+26,0);
        int len = str.size();
        string tmp;
        for (int j = 0; j < len; ++j) {
            str[j] = toupper(str[j]);
            if (alpha[str[j]-'A'] == 0) {
                tmp += str[j];
                alpha[str[j]-'A']++;
            }
        }
        if (alpha[ch-'A'] == 1){
            ans.push_back(tmp);
        }
    }
    for (string s: ans) {
        cout << s <<'\n';
    }
}