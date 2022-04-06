#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i <= 16; ++i) {
        cout << i << " => "  << (i & -i) << '\n';

    }
}