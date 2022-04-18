#include "bits/stdc++.h"

using namespace std;

int fastSum(int n){
    if (n == 1) return 1;
    if (n%2 == 1) return fastSum(n-1)+n;
    return 2* fastSum(n/2) + (n/2)*(n/2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << fastSum(n);

}