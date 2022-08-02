#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = n-60; i <=n; ++i) {
        int sum = 0;
        int v = i;
        while (v){
            sum += v %10;
            v /=10;
        }
        if(i+sum == n){
            cout << i;
            exit(0);
        }
    }
    cout << 0;
}