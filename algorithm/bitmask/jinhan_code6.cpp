#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 6;  // 00000000 00000000 00000000 00001010 (2)
    cout << n << '\n';
    cout << n-1 << '\n';  // 00000000 00000000 00000000 00000101 (2)
    cout << ~(n-1) << '\n';  // 11111111 11111111 11111111 1111101
}