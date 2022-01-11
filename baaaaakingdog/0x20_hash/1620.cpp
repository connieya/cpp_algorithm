#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> ans;
string arr[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        ans[arr[i]] = i;
    }
    while(m--){
        string query;
        cin >> query;
        if(isdigit(query[0]))
            cout << arr[stoi(query)] << '\n';
        else
            cout << ans[query] << '\n';
    }
}