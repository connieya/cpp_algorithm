#include "bits/stdc++.h"

using namespace std;

int _pow(int x ,int i) {
    int ret = 1;
    while (i){
        if(i % 2) ret *= x;
        x *= x;
        i /= 2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << _pow(2,4) << '\n';
    cout << _pow(3,3) << '\n';
    cout << _pow(2,6) << '\n';
    cout << _pow(2,16) << '\n';
    cout << _pow(2,20) << '\n';
}