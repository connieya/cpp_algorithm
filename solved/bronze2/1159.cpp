#include "bits/stdc++.h"

using namespace std;

int alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        alpha[input[0] - 'a']++;
    }

    bool flag = true;
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] >= 5) {
            flag = false;
            cout << (char)(i+'a');
        }
    }
    if (flag) {
        cout << "PREDAJA";
    }

}