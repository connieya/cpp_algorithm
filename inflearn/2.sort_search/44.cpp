#include "bits/stdc++.h"

#define INF 200001

using namespace std;

int arr[INF];
int cntHorse(int mid ,int n){
    int prev =arr[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] -prev >= mid){
            cnt++;
            prev = arr[i];

        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int lt = 1;
    int rt = arr[n - 1];
    int ans;
    while (lt <= rt) {
        int mid = (lt + rt) / 2;
        if (cntHorse(mid,n) >= c){
            lt = mid+1;
            ans = mid;
        }else {
            rt = mid-1;
        }
    }
    cout << ans;

}