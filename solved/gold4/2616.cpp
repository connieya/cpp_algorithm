#include "bits/stdc++.h"

using namespace std;

int arr[50001];
int prefix_sum[50001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int sum_prefix = 0;
    for (int i = 0; i < n; ++i) {
        sum_prefix += arr[i];
        prefix_sum[i+1] = sum_prefix;
    }
    for (int i = 1; i <= n; ++i) {
        cout << prefix_sum[i] << ' ';
    }
    cout << '\n';

}