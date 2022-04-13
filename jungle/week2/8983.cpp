#include "bits/stdc++.h"
#define INF 100001
using namespace std;

int shooting[INF];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M, N, L, ans = 0;
    cin >> M >> N >> L;
    for (int i = 0; i < M; ++i) {
        cin >> shooting[i];
    }
    sort(shooting, shooting + M);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        if (y > L) continue;
        int res = lower_bound(shooting, shooting + M, x) - shooting;
        if (shooting[res] == x) {
            if (y <= L) ans++;
            continue;
        }
        if (res == 0) {
            if (abs(shooting[res] - x) + y <= L) {
                ans++;
            }
        } else if (res == M) {
            if (abs(shooting[res - 1] - x) + y <= L) {
                ans++;
            }
        } else {
            if (abs(shooting[res - 1] - x) + y <= L || abs(shooting[res] - x) + y <= L) {
                ans++;
            }
        }

    }

    cout << ans;
}