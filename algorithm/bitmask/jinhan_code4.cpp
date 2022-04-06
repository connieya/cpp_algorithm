#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << bitset<32>(0) << '\n'; // 00000000 00000000 00000000 00000000 (2)
    cout << bitset<32>(~0) << '\n'; // 11111111 11111111 11111111 1111111 (2)
    cout << bitset<32>(1<<3) << '\n'; // 00000000 00000000 00000000 00001000 (2)
    cout << bitset<32>((1<<3)-1) << '\n'; // 00000000 00000000 00000000 00000111 (2)

}