#include "bits/stdc++.h"

using namespace std;

int arr[9];
int ch[9];
int team[3];
int sum[3];
int ans = 1e6;

void dfs(int L){
    if (L == 9){
        sum[0] = sum[1] = sum[2] = 0;
        for (int i = 0; i < 9; ++i) {
            sum[ch[i]] += arr[i];
        }
        sort(sum,sum+3);
        int sub = abs(sum[0]-sum[2]);
        if (ans > sub){
            ans = sub;
        }
        return;
    }
    for (int i = 0; i < 3; ++i) {
        if (team[i] < 3){
            team[i]++;
            ch[L] = i;
            dfs(L+1);
            team[i]--;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
    }
    dfs(0);
    cout << ans;

}