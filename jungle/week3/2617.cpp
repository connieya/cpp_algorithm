#include "bits/stdc++.h"

using namespace std;

vector<int> marble[100];
vector<int> light[100];

int search_heavy(int start) {
    int cnt = 0;
    for (int next: marble[start]) {
        cnt++;
        cnt += search_heavy(next);
    }
    return cnt;
}

int search_light(int start) {
    int cnt = 0;
    for (int next: light[start]) {
        cnt++;
        cnt += search_light(next);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        marble[a].push_back(b);
        light[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (search_heavy(i) >= (n + 1) / 2 || search_light(i) >= (n + 1) / 2) {
            ans++;
        }
    }
    cout << ans;
}