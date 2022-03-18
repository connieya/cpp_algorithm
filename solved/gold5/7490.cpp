#include "bits/stdc++.h"

using namespace std;

char op[18];

void dfs(int sum ,int L, int idx ,int n){
    if (L == n+1){
        if (sum == 0){
            for (int i = 1; i <= n*2-1; ++i) {
                cout << op[i];
            }
            cout <<'\n';
        }
        return;
    }
    op[idx] = ' ' , op[idx+1] = L+48;
    dfs(sum*10+L,L+1, idx+2,n);
    op[idx] = '+' , op[idx+1] = L+48;
    dfs(sum+L,L+1,idx+2, n);
    op[idx] = '-' , op[idx+1] = L+48;
    dfs(sum-L,L+1,idx+2,n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin >> t;
    op[1] = '1';
    while (t--) {
        cin >> n;
        dfs(1,2,2,n);
        cout <<'\n';
    }


}