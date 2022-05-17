#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

bool d[10];

void init(ll num) {
    while (num) {
        d[num % 10] = true;
        num /= 10;
    }
}

bool solve(ll num) {
    for (int i = 1; i <= 9; ++i) {
        if (!d[i]) continue;
        if (num % i) return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll answer , loop = 1;
    cin >> answer;
    init(answer);
    while (1) {
        for(int i=0; i < loop; i++){
            if(solve(answer*loop+i)){
                cout << answer*loop+i;
                exit(0);
            }
        }
        loop *= 10;
    }
}