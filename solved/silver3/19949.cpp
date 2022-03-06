#include "bits/stdc++.h"

using namespace std;

int answer[10];
int yj[10];


void dfs(int L , int &ans ,int t) {
    if (L == 10){

        if (t>=5){
            ans++;
        }
        return;
    }
    for (int i = 1; i <=5; ++i) {
        yj[L] = i;
        if (L > 1 && yj[L-1] == i && yj[L-2] == i) continue;
        dfs(L+1,ans, t+(yj[L] == answer[L]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 10; ++i) {
        cin >> answer[i];
    }
    int ans = 0;
    dfs(0 , ans,0);
    cout << ans;
}