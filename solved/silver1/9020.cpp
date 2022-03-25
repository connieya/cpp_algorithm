#include "bits/stdc++.h"

#define INF 10000
using namespace std;

bool isPrime[INF];

void init() {
    for (int i = 2; i * i < INF; ++i) {
        if (isPrime[i]) continue;
        for (int j = i * i; j <= INF; j += i) {
            isPrime[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    init();
    while (t--) {
        cin >> n;
        int a = n / 2, b = n / 2;
        while (1){
            if (!isPrime[a] && !isPrime[b]){
                cout << a <<  ' ' << b << '\n';
                break;
            }
            a--;
            b++;
        }

    }
}