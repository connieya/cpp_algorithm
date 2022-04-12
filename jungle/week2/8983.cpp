#include "bits/stdc++.h"

#define INF 100001
using namespace std;

int shooting[INF];
vector<pair<int, int >> target;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M, N, L, ans = 0, dis;
    cin >> M >> N >> L;
    for (int i = 0; i < M; ++i) {
        cin >> shooting[i];
    }
    sort(shooting, shooting + M);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        if (y > L) continue;
        int lt = 0, rt = M - 1;
        while (lt <= rt) {
            int mid = (lt + rt) / 2;
            if (mid == 0) {
                dis = abs(shooting[mid] - x) + y;
            } else {
                dis = min(abs(shooting[mid - 1] - x) + y, abs(shooting[mid + 1] - x) + y);
            }

            if (dis <= L) {
                ans++;
                break;
            }
            if (mid >= x) {
                rt = mid - 1;
            } else {
                lt = mid + 1;
            }
        }
    }

    cout << ans;
}