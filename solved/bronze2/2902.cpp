#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string name;
    cin >> name;
    int len = name.length();
    for (int i = 0; i < len; ++i) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            cout << name[i];
        }
    }
}