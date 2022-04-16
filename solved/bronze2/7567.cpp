#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int sum = 10;
    int len = str.length();
    for (int i = 1; i < len; ++i) {
        if (str[i] == str[i - 1]) {
            sum += 5;
        } else {
            sum += 10;
        }
    }
    cout << sum;
}