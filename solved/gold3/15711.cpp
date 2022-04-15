#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const int INF = 2000000;

bool isPrime[INF + 1];
vector<ll> primes;

void eratosthenes() {
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i <= INF; ++i) {
        if (isPrime[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * 2; j <= INF; j += i) {
            isPrime[j] = true;
        }
    }
}

bool divide(ll value) {
    if (value <= INF) {
        return !isPrime[value];
    }
    for (int i = 0; i < primes.size(); ++i) {
        if ((value % primes[i]) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    int t;
    cin >> t;
    while (t--) {
        ll a, b, S;
        cin >> a >> b;
        S = a + b;
        if (S == 2) {
            cout << "NO" << '\n';
        } else if (S % 2 == 0) { // 골드바흐의 추측;
            cout << "YES" << '\n';
        } else {
            if (divide(S - 2)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }


    }
}