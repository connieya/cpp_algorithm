#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    cout << INT_MAX + 1 << '\n';
    int n = 0b0010;
    cout << n << '\n';
    n |= 1 << 3; // 3번째 비트 켜기
    cout << n << '\n';
    n &= ~(1<<3); // 3번재 비트 끄기
    cout << n << '\n';

}
