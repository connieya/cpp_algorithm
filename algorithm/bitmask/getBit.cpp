#include "bits/stdc++.h"

using namespace std;


void toBinary(int num) {
    if (!num) {
        cout << '\n';
        return;
    }
    toBinary(num/2);
    cout << (num&1);
}


bool getBit(int num , int i){
    return (num & 1 << i) != 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 441;
    toBinary(n);
    cout << '\n';
    cout << getBit(n,0) << '\n';
    cout << getBit(n,1) << '\n';
    cout << getBit(n,2) << '\n';
    cout << getBit(n,3) << '\n';
    cout << getBit(n,4) << '\n';
    cout << getBit(n,5) << '\n';
}