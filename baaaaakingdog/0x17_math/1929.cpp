#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> m >> n;
    vector<bool> isPrime(n+1 ,true);
    isPrime[1] = false;
    for (int i = 2; i*i <= n; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= n; j+=i) {
            isPrime[j] = false;
        }
    }
    for (int i = m; i<=n; i++) {
        if (isPrime[i]) {
            cout << i << '\n';
        }
    }
}

