#include "bits/stdc++.h"

using namespace std;
bool isPrime(int n) {
    if (n<=1) return false;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , num ,ans = 0;
    cin >>n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        ans += isPrime(num);

    }
    cout << ans;
}