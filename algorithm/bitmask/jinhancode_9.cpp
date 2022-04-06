#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // n의 가장 오른쪽 1 끄기
    int n = 0b00111010;
    cout << n << '\n';
    n &= n-1;
    cout << n << '\n';
}