#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        cout << str[i];
        if (i % 10 == 9) {
            cout << '\n';
        }
    }
}