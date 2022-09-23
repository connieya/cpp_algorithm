#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string file;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        cin >> file;
        v.push_back(file.substr(file.find('.')+1));
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n;) {
        int j= i+1;
        int cnt = 1;
        while (j <n && v[i] == v[j]){
            cnt++;
            j++;
        }
        cout << v[i] << ' ' << cnt << '\n';
        i = j;
    }
}