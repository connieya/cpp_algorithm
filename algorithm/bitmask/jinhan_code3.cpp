#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0b0010010;
    if (n & (1<< 4)){
        cout << " bit on";
    }else {
        cout << " bit off";
    }
}