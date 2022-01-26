#include "bits/stdc++.h"

using namespace std;

long long fn[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , num;
    long long k;
    cin >> n;
    fn[1] =1;
    for (int i = 2; i <= 20; ++i) {
       fn[i] = fn[i-1]*i;
    }

}