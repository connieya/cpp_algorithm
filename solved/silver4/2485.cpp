#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int g = arr[1] - arr[0];
    for (int i = 2; i < n; ++i) {
        g = gcd(g, arr[i] - arr[i - 1]);
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (arr[i] - arr[i - 1]) / g - 1;
    }
    cout << ans;


}