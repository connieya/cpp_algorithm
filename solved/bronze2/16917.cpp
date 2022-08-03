#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = x*a+b*y;
    for (int i = 1; i <= 100000; ++i) {
        int price = 2*i*c + max(0,x-i)*a + max(0,y-i)*b;
        if(ans > price) ans = price;
    }
    cout << ans;
}