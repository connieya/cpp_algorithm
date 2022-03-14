#include "bits/stdc++.h"

using namespace std;

int arr[500001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m ,target;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> target;
        cout << upper_bound(arr,arr+n,target)- lower_bound(arr,arr+n,target) << ' ';
    }
}