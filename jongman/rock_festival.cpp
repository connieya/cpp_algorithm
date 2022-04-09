#include "bits/stdc++.h"

using namespace std;

int arr[1001];
int prefix_sum[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    double ans = 100000000;
    while (t--) {
        cin >> n >> m;
        int sum_value = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum_value += arr[i];
            prefix_sum[i+1] = sum_value;
        }
        for (int i = m; i <=n; ++i) {
            for (int j = i; j <=n; ++j) {
                double avg = (double ) (prefix_sum[j]-prefix_sum[j-i]) / i;
                if (ans > avg){
                    ans = avg;
                }
            }
        }
        cout << ans <<'\n';
    }


}