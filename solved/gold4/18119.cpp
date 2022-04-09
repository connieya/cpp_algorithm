#include "bits/stdc++.h"

using namespace std;

int words[10001];

int countWords(int n, int T) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if ((words[i] & T) == words[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int T = (1 << 27) - 1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        for (char ch: input) {
            words[i] |= 1 << (ch - 'a');
        }
    }
    int o;
    char x;
    for (int i = 0; i < m; ++i) {
        cin >> o >> x;
        T ^= 1 << (x - 'a');
        cout << countWords(n, T) << '\n';
    }
}