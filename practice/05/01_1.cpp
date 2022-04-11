#include "bits/stdc++.h"

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string pattern;
    int n ;
    cin >> pattern >> n;
    int i, ans = 0;
    for(i=3; i<pattern.size(); i++){
        if (pattern.substr(0,i) == pattern.substr(i,i)){
            for (char num: pattern.substr(0,i)) {
                ans += (num-48);
            }
            break;
        }
    }
    ans *= n/i;
    for (int j = 0; j < n % i; ++j) {
        ans += pattern[j]-48;
    }
    cout << ans;
}