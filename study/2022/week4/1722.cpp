#include "bits/stdc++.h"

using namespace std;

long long fn[21];
int arr[21];
bool check[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num;
    long long k;
    cin >> n;
    fn[0] = 1;
    fn[1] = 1;
    vector<int> ans;
    for (int i = 2; i <= 20; ++i) {
        fn[i] = fn[i - 1] * i;
    }
    cin >> num;
    if (num == 1) {
        cin >> k;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (check[j]) continue;
                if (fn[n - 1 - i] < k) {
                    k -= fn[n - 1 - i];
                } else {
                    cout << j << ' ';
                    check[j] = true;
                    break;
                }
            }
        }
    } else {
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < arr[i]; ++j) {
                if(!check[j]) {
                    ans += fn[n-1-i];
                }
            }
            check[arr[i]] = true;
        }
        cout << ans+1;
    }


}