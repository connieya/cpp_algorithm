#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    int len = 1;
    int ans = 0;
    int add = 9;
    while (n > sum+add) {
        ans = ans + (len*add);
        sum = sum +add;
        len++;
        add *= 10;
    }
    ans += (n - sum) * len;
    cout << ans;
}