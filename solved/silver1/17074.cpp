#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt = 0, tmp ,ans=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            cnt++;
            tmp = i;
        }
    }
    if (!cnt) {
        cout << n;
    } else if (cnt > 1) {
        cout << 0;
    } else {
        if (!tmp) {
            if (arr[tmp] <= arr[tmp + 2]) {
                cout << 2;
            } else {
                cout << 1;
            }
        } else if (tmp == n - 2) {
            if (arr[tmp - 1] <= arr[tmp + 1]){
                cout << 2;
            }else {
                cout << 1;
            }
        } else {
            if (arr[tmp] <= arr[tmp+2]){
                ans++;
            }
            if (arr[tmp-1] <= arr[tmp+1]){
                ans++;
            }
            cout << ans;
        }
    }
}