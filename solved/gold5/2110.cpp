#include "bits/stdc++.h"

using namespace std;

int n, c;

int countWifi(int dist, vector<int> &v) {
    int len = v.size();
    int cnt = 1;
    int prev = v[0];
    for (int i = 1; i < len; ++i) {
        if (v[i] - prev >= dist) {
            prev = v[i];
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int lt = 0, rt = v[n - 1];
    int ans;
    while (lt <= rt) {
        int mid = (lt + rt) / 2;
        int res = countWifi(mid, v);
        if (res >= c) { // 공유기를 많이 설치한다는 말 -> mid값이 작다는 말
            lt = mid + 1;
            ans = mid;
        } else {
            rt = mid - 1;
        }
    }
    cout << ans;

}