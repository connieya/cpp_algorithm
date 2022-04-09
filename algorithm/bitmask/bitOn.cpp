#include "bits/stdc++.h"

using namespace std;

void toBinary(int num) {
    if (!num) {
        cout << '\n';
        return;
    }
    toBinary(num/2);
    cout <<(num & 1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0b0010; // 2
    n |= 1 << 3;  // 0b1010
    cout << n;
    toBinary(n);
}