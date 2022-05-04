#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int g,l ,a ,b , mx = INT_MAX;
    cin >> g >> l;
    int t = l/g;
    for (int i = 1; i*i <= t ; ++i) {
        if (t % i == 0 && gcd(i,t/i) == 1){
            a = i;
            b = t/i;
        }
    }
    cout << a*g << ' ' << b*g;
}