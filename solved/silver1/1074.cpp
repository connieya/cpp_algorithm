#include "bits/stdc++.h"

using namespace std;

int recursive(int n ,int r  , int c) {
    if (n==0) return 0;
    int half = 1 << (n-1);
    if (r < half  && c < half) return recursive(n-1,r,c); // 1구역
    if (r < half && c >= half) return half*half + recursive(n-1,r,c-half); // 2구역
    if (r >= half && c < half) return half*half*2 + recursive(n-1,r-half,c);  // 3구역
    return 3*half*half+recursive(n-1,r-half,c-half); // 4구역

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,r,c;
    cin >> n >> r >> c;
    cout <<  recursive(n,r,c);

}