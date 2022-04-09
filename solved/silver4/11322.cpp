#include "bits/stdc++.h"

using namespace std;

void toBinary(int num) {
    if (!num) return;
    toBinary(num / 2);
    cout << (num & 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    unsigned long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        int k = 0;
        while (!(1 << k & n)) {
            k++;
        }
        toBinary((1 << k));
        cout << '\n';
    }
}