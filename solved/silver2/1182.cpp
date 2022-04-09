#include "bits/stdc++.h"
using namespace std;

int arr[21];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = 1; i < 1<<n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)){
                sum += arr[j];
            }
        }
        if (sum == s) cnt++;
    }
    cout << cnt;
}