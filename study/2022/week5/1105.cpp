#include "bits/stdc++.h"

using namespace std;

int solve(string L , string R) {
    int len = L.length();
    if (len != R.length()) return 0;
    int cnt = 0;
    for(int i=0; i<len; i++){
        if(L[i] != R[i]) break;
        if (L[i] == R[i] && L[i] == '8') {
            cnt++;
        }

    }
    return cnt;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string L, R;
    cin >> L >> R;
    cout << solve(L,R);
}