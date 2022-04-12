#include "bits/stdc++.h"

using namespace std;
string str;
bool check(int start , int end){
    for (int i = start; i < end; i+=2) {
        if (i==end-1 && str[i] != 'I') return false;
        if (str[i] != 'I' || str[i+1] != 'O') return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m, ans = 0;
    cin >> n >> m;
    cin >> str;
    int t = 2*n+1;
    for (int i = 0; i <= m-t; ++i) {
        if (str[i] == 'O') continue;
        if (check(i,i+t)){
            ans++;
        }
    }
    cout << ans;
}