#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<pair<int,int>> S;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        while (!S.empty() && S.top().first <= value){
            S.pop();
        }
        if (S.empty()){
            ans.push_back(0);
        }else {
            ans.push_back(S.top().second);
        }
        S.push({value,i});
    }
    for (int idx : ans) {
        cout << idx <<' ';
    }
}