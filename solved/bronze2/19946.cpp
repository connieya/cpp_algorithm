#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long n;
    cin >> n;
    int cnt = 0;
    while (n) {
        cnt += (n & 1);
        n >>= 2;
    }
    cout << cnt<< '\n';
}