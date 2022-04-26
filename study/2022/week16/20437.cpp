#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string str;
        int k;
        cin >> str >> k;
        int min_len = INT_MAX;
        int max_len = -1;
        vector<int> alpha(26);
        for (char ch: str) {
            alpha[ch - 'a']++;
        }

        for (int i = 0; i < str.length(); ++i) {
            if (alpha[str[i] - 'a'] < k) continue;
            int cnt = 0;
            int length  = 0;
            for (int j = i; j < str.length(); j++) {
                length++;
                if (str[i] == str[j]) cnt++;
                if (cnt == k) {
                    min_len = min(min_len, length);
                    max_len = max(max_len, length);
                    break;
                }
            }
        }
        if (max_len == -1 ) {
            cout << -1 << '\n';
        } else {
            cout << min_len << ' ' << max_len << '\n';
        }
    }
}