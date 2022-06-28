#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n) ,b(m);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0 , j = 0 ;
    while (i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans.push_back(a[i++]);
        }else {
            ans.push_back(b[j++]);
        }
    }
    while (i < a.size()){
        ans.push_back(a[i++]);
    }
    while (j < b.size()){
        ans.push_back(b[j++]);
    }

    for(auto v : ans){
        cout << v << ' ';
    }
}
