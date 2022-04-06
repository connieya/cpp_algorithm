#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    if (b=="*"){
        cout << "1";
        for (int i = 2; i < a.length()+c.length(); ++i) {
            cout << "0";
        }

    }else {
        int start = max(a.length(),c.length());
        for (int i = start; i>0; --i) {
            cout << (i == a.length()) + (i == c.length());
        }

    }
}