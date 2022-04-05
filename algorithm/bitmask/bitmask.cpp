#include "bits/stdc++.h"

using namespace std;

bool getBit(int num , int i) {
    return (num & (1 << i)) != 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num = 9;
    cout << getBit(num,3) << '\n';
    num = 8;
    cout << getBit(num,3) << '\n';
    num = 7;
    cout << getBit(num,3) << '\n';
}