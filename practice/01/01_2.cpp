#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> words;
    string str;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        words.push_back(str);
    }
    int len = words.size();
    string res  = words[0];
    for (int i = 0; i < len; ++i) {
        while (words[i].find(res) != 0) {
            res = res.substr(0,res.size()-1);
        }
    }
    cout << res;
}