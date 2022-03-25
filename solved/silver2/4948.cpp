#include "bits/stdc++.h"
#define INF 250000

using namespace std;

bool isPrime[INF];

void init() {
    isPrime[1] = true;
    for (int i = 2; i*i <= INF ; ++i) {
        if (isPrime[i]) continue;
        for (int j = i*i; j <= INF; j+=i) {
            isPrime[j] = true;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    init();
    while (1) {
        cin >> n;
        if (!n) break;
        int t = 2*n;
        int cnt = 0;
        for (int i = n+1; i <= t; ++i) {
            if (!isPrime[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}