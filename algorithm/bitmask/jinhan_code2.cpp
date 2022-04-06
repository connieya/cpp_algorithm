#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0b1000; // 8
    cout << n << '\n';
    n ^= 1 << 3; // 3번째 비트 뒤집기
    cout << n << '\n';
    n ^= 1 << 2; // 2번째 비트 뒤집기
    cout << n << '\n';
}