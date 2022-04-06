#include "bits/stdc++.h"

using namespace std;

void toBinary(int num) {
    if (num == 0) {
        cout << '\n';
        return;
    }
    toBinary(num / 2);
    cout << (num & 1);
}

int PopCount(int num) {
    cout << '\n';
    int ret = 0;
    while (num) {
        if (num & 1) ret++;
        num >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 58;
    toBinary(n);
    cout << PopCount(n);
}