#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    vector<string> v;
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        v.push_back(str.substr(i));
    }
    for (auto s: v) {
        cout << s << '\n';
    }
}