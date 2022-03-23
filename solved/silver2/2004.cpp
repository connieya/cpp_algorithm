#include "bits/stdc++.h"
typedef long long ll;
using namespace std;

int calc(int n, int div){
    if (n==0) return 0;
    return n/div+ calc(n/div,div);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    if (n == m || m == 0) {
        cout << 0;
        exit(0);
    }
    cout << min(calc(n,5)- calc(n-m,5)- calc(m,5) , calc(n,2)- calc(n-m,2)- calc(m,2));
}