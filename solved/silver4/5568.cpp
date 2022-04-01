#include "bits/stdc++.h"

using namespace std;

string arr[11];
bool visited[11];
set<string> S;
int n,k;

void dfs(int L , string str) {
    if (L == k){
        S.insert(str);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]){
            visited[i] = true;
            dfs(L+1,str+arr[i]);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0,"");
    cout << S.size();
}