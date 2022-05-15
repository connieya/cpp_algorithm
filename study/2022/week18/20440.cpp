#include "bits/stdc++.h"

#define INF 210000001

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    vector<pair<int, int>> input;
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        input.push_back({s, e});
        v.push_back(s);
        v.push_back(e);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> sum(v.size());
    vector<int> arr(v.size());
    for (auto &i: input) {
        int start = lower_bound(v.begin(), v.end(), i.first)-v.begin();
        int end = lower_bound(v.begin(), v.end(), i.second)-v.begin();
        sum[start]++;
        sum[end]--;
        arr[start] = i.first;
        arr[end] = i.second;
    }
    for (int i = 1; i < sum.size(); ++i) {
        sum[i] += sum[i - 1];
    }
    int res = 0;
    for (auto &s: sum) {
        res = max(res, s);
    }
    cout << res << '\n';
    int x, y;
    bool flag = false;
    for (int i = 0; i < sum.size(); ++i) {
        if (!flag && sum[i] == res) {
            flag = true;
            x = arr[i];
        }
        if (flag && sum[i] != res) {
            y = arr[i];
            break;
        }
    }
    cout << x << ' ' << y;

}