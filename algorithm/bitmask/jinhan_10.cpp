#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0b00111011; // n = 0011 1011 (2)
    cout << n << '\n'; // 59
    n |= n+1; // n + 1 = 0011 1100 (2)
    cout << n << '\n'; // n = 0011 1111(2) , 63
}