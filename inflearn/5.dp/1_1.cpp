#include "bits/stdc++.h"

using namespace std;

int dp[50];
int func(int n){
    if (n<=2) return n;
    if (dp[n]) return dp[n];
    return dp[n] = func(n-1)+ func(n-2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << func(n);

}