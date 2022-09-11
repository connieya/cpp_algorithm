#include "bits/stdc++.h"

using namespace std;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> prime;
    prime.push_back(2);
    for (int i = 3; i <= n; ++i) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    int lt = 0, rt = 0, len = prime.size(), sum = 0;
    while (rt < len) {
        if (sum < n) {
            sum += prime[rt++];
        } else {
            if (sum == n) ans++;
            sum -= prime[lt++];
        }
    }
    while (sum >= n && lt < len) {
        if (sum == n) ans++;
        sum -= prime[lt++];
    }
    cout << ans;
}