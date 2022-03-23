#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,num;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        v.push_back(num);
        sort(v.begin(),v.end());
        int len = v.size();
        if (len % 2 == 1){
            cout << v[len/2] << '\n';
        }else {
            cout << v[len/2-1] << '\n';
        }
    }
}