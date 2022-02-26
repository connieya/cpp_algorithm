#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    char ch;
    string str;
    cin >> n >> ch;
    ch = toupper(ch);
    for (int i = 0; i < n; ++i) {
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        if (str.find(ch) == string::npos) continue;
        string res = "";
        int len = str.size();
        for (int j = 0; j < len; ++j) {
            if ((str.find(str[j])) == j) {
                res += str[j];
            }
        }
        cout << res <<'\n';
    }
}