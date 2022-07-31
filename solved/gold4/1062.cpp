#include "bits/stdc++.h"

using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    string str;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        int temp = 0;
        for (int j = 0; j < str.length(); ++j) {
            temp |= 1 << (str[j] - 'a');
        }
        v.push_back(temp);
    }
    int ans = 0;
    vector<int> arr(26);
    fill(arr.end() - k, arr.end(), 1);
    do {
        int cur = 0, cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i]) {
                cur |= 1 << i;
            }
        }
        for (int alpha: v) {
            if (!(alpha & ~cur)) cnt++;
        }
        if (cnt > ans) {
            ans = cnt;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    cout << ans;
}