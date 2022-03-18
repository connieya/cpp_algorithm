#include "bits/stdc++.h"

using namespace std;

int gcb(int a, int b){
    if (b==0) return a;
    return gcb(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,a,b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << a*b/ gcb(a,b) << '\n';
    }
}