#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    int n =0;
    int i;
    for (i = 1; n < x; ++i) {
        n += i;
    }
    cout << n << ' ' << i;
}