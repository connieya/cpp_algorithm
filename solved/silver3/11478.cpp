#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> s;
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j <= len - i; ++j) {
            s.push_back(str .substr(i, j));
        }
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    cout << s.size();
}