#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int small(int lt, int rt, int target, vector<int> &v) {
    int mid = (lt + rt) / 2;
    if (v[mid] == target) return v[mid];
    if (v[mid] < target) {
        if (mid == rt) return v[mid];
        else return max(small(mid + 1, rt, target, v), v[mid]);
    } else {
        if (mid == lt) return -1;
        else return small(lt, mid - 1, target, v);
    }
}

int large(int lt, int rt, int target, vector<int> &v) {
    int mid = (lt + rt) / 2;
    if (v[mid] == target) return v[mid];
    if (v[mid] > target) {
        if (mid == lt) return v[mid];
        else return min(large(lt, mid - 1, target, v), v[mid]);
    } else {
        if (mid == rt) return 1000000000;
        else return large(mid + 1, rt, target, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        ll answer = 0;
        for (auto aa: a) {
            int s = small(0, m - 1, aa, b);
            int l = large(0, m - 1, aa, b);
            if (s == -1) s = b[0];
            if (l == -1) l = b[m - 1];
            if (abs(aa - s) <= abs(aa - l)) {
                answer += s;
            } else {
                answer += l;
            }
        }
        cout << answer << '\n';
    }
}