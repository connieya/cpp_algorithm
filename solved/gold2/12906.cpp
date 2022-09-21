#include "bits/stdc++.h"

using namespace std;
int cnt[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> stick(3, "");
    vector<string> finish(3, "");
    for (int i = 0; i < 3; ++i) {
        int cnt;
        cin >> cnt;
        string str = "";
        if (cnt) {
            cin >> str;
            for (char ch: str) {
               cout << ch << ' ';
               cnt[ch-'A']++;
            }
            cout << '\n';
        }
        stick[i] = str;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            finish[i] += (char)('A' + i);
        }
    }
    for (int i = 0; i < 3; ++i) {
        cout << finish[i] << '\n';
    }


}