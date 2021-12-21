#include "bits/stdc++.h"

using namespace std;
unordered_map<string ,vector<string>> m;
unordered_map<string, bool> visited;
vector<string> ans;

void dfs(string s){
    if(visited[s]) return;
    visited[s] = true;
    ans.push_back(s);
    for(auto e : m[s]) {
        dfs(e);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string p , is ,q;
        cin >> p >> is >> q;
        m[p].push_back(q);
    }
    dfs("Baba");
    sort(ans.begin(),ans.end());
    for (auto a : ans){
        if(a!= "Baba"){
            cout << a <<'\n';
        }
    }
}