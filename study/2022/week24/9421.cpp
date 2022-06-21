#include "bits/stdc++.h"

using namespace std;

bool isPrime[1000001];
int sg[1000001];

bool solve(int num) {
    if (num == 1) return sg[num] = 1;
    if (sg[num] != -1) return sg[num];
    sg[num] = 0;
    int next = 0, original = num;
    while (num) {
        next += (num % 10) * (num % 10);
        num /= 10;
    }
    return sg[original] = solve(next);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    memset(sg, -1, sizeof(sg));
    for (long long i = 2; i <= n; i++) {
        if (!isPrime[i]) {
            for (long long j = i * i; j <= n; j += i) {
                isPrime[j] = true;
            }
            if (solve(i)) {
                cout << i << '\n';
            }
        }

    }
}