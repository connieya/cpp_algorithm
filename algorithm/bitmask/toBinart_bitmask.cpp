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
    int n = 71; // 6
    toBinary(n);
    toBinary(n+1);
    n |= n+1;
    toBinary(n);
}