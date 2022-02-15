#include "bits/stdc++.h"

using namespace std;

int arr[500001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, num, idx = 1;
    int idx2, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> q;
        if (q == 3) {
            cnt = 0;
            idx2 = idx;
            if (arr[idx2] == 1) {

            } else {
                while (1) {
                    idx2++;
                    if (idx2 > n) {
                        idx2 = 1;
                    }
                    cnt++;
                    if (arr[idx2] == 1) {
                        break;
                    }
                    if (cnt == n - 1) {
                        break;
                    }
                }
            }

            if (cnt == n - 1) {
                cout << -1 << '\n';
            } else {
                cout << cnt << '\n';
            }
        } else if (q == 1) {
            cin >> num;
            arr[num] = (arr[num] == 1) ? 0 : 1;
            for (int i = 1; i <= n; i++) {
                cout << arr[i] << ' ';
            }
            cout << '\n';
        } else {
            cin >> num;
            num = num % n;
            idx += num;
            if (idx > n) {
                idx = idx - n;
            }
        };
    }
}