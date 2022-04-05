#include "bits/stdc++.h"

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int H,M,S,T;
    cin >> H >> M >> S >> T;
    S += T%60;
    M += T/60;
    M += S/60;
    S = S%60;
    H += M/60;
    M =M%60;
    cout << H%24 << ' ' << M << ' ' << S;
}