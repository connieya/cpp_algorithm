#include "bits/stdc++.h"
#define INF 100001

using namespace std;

double arr[INF];

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
    for (int i = 0; i < n - 1; ++i) {
       arr[n-1] = arr[n-1]+ arr[i]/2;
    }
    cout << arr[n-1];

}