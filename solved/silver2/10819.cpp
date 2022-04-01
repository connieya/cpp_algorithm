#include "bits/stdc++.h"

using namespace std;

int arr[9],ans = INT_MIN;

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
    sort(arr,arr+n);
    do {
        int sum =0;
        for (int i = 0; i < n-1; ++i) {
            sum += abs(arr[i]-arr[i+1]);
        }
        if (ans < sum){
            ans = sum;
        }

    } while (next_permutation(arr,arr+n));
    cout << ans;
}