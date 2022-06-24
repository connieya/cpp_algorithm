#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    cin >> n >> str;
    int ans  = 0;
    for(char ch : str) ans += ch-'0';
    cout << ans;
}