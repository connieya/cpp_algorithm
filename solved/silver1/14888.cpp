#include "bits/stdc++.h"

using namespace std;

int arr[11];
int op[4];
int n,MX =INT_MIN ,MN = INT_MAX;

void dfs(int L,int sum) {
    if (L == n) {
        MX = max(sum,MX);
        MN = min(sum,MN);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (op[i] > 0){
            if (i==0){
                op[i]--;
                dfs(L+1,sum+arr[L]);
                op[i]++;
                continue;
            }
            if (i==1){
                op[i]--;
                dfs(L+1,sum-arr[L]);
                op[i]++;
                continue;
            }
            if (i==2){
                op[i]--;
                dfs(L+1,sum*arr[L]);
                op[i]++;
                continue;
            }
            if (i==3){
                op[i]--;
                dfs(L+1,sum/arr[L]);
                op[i]++;
                continue;
            }


        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
    }
    dfs(1,arr[0]);
    cout << MX << '\n' << MN;
}