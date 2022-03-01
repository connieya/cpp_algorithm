#include "bits/stdc++.h"

using namespace std;

int arr[100001];
bool checked[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ans = n * (n + 1) / 2;
    int lt = 0;
    int rt = 1;
    checked[arr[lt]] = true;
    while (rt < n) {
        if (checked[arr[rt]]){
            checked[arr[lt]] = false;
            lt++;
            ans -= n-rt;
        }else {
            checked[arr[rt]] = true;
            rt++;
        }
    }
    cout << ans;
}