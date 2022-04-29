#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, ans = 0;
    string str;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n;) {
        string tmp = "";
        while (i < n && isdigit(str[i])) {
            tmp += str[i++];
        }
        while (i < n && !isdigit(str[i])) {
            i++;
        }
        if (tmp.length() > 0) {
            ans += stoi(tmp);
        }
    }
    cout << ans;
}