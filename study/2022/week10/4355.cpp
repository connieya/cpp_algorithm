#include "bits/stdc++.h"

using namespace std;

int gcb(int a, int b){
    if (b==0) return a;
    return gcb(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        int n;
        cin >>  n;
        if (!n) break;
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (gcb(i,n) == 1){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}