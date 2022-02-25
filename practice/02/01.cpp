#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int res = 0;
    int temp = 0;
    string tmp;
    for (char ch: str) {
        if (isdigit(ch)) {
            temp = temp*10 +(ch-48);
        } else {
           res += temp;
           temp = 0;
        }
    }
    cout << res+temp;
}