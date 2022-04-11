#include "bits/stdc++.h"

using namespace std;

int arr[51];

void print(int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; ++i) {
        if (arr[i] == i+1) continue;
        if (arr[i] > i+1) {
            cout << 0;
            return 0;
        }
        arr[i] += k;
        i--;
        sort(arr,arr+n);
    }
    cout << 1;
}