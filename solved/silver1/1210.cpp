#include "bits/stdc++.h"

using namespace std;

int n,k ,ans = 0;
int arr[11];
bool flag;

void dfs(int sum , int L) {
    if (sum  > n || flag) return;
    if (sum == n) {
        ans++;
        if (ans == k) {
            flag = true;
            for (int i = 0; i < L; ++i) {
                if (i==L-1){
                    cout << arr[i];
                    continue;
                }
                cout << arr[i] << "+";
            }
        }
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        arr[L] = i;
        dfs(sum+i, L+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    dfs(0,0);
    if (!flag){
        cout << -1;
    }

}