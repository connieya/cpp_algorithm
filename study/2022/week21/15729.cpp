#include "bits/stdc++.h"

using namespace std;

int ans[1000000];
int arr[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (ans[i] != arr[i]) {
            res++;
            ans[i] = !ans[i];
            ans[i + 1] = !ans[i + 1];
            ans[i + 2] = !ans[i + 2];
        }
    }
    if (ans[n - 2] != arr[n - 2]) {
        res++;
        ans[n - 1] = !ans[n - 1];
    }
    if (ans[n - 1] != arr[n - 1])res++;
    cout << res;
}