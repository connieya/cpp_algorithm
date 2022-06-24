#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m , k =0;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &i : a){
        cin >> i;
    }
    sort(a.begin(),a.end());
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if(binary_search(a.begin(),a.end(),t)) k++;
    }
    cout << n+m-2*k;
}