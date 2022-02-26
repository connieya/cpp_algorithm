#include "bits/stdc++.h"

using namespace std;

int n, d, k;
bool checked[16];
int st[30001];
int ans = -1;
void dfs(int L, int start , int sum) {
    if (L== k) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if ( (sum & st[i]) == st[i]){
                cnt++;
            }
        }
        ans = max(ans,cnt);
        return;
    }
    for (int i = start; i <= d; ++i) {
        if (!checked[i]){
            checked[i] = true;
            dfs(L+1,i+1,sum+ pow(2,i-1));
            checked[i] = false;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d >> k;
    for (int i = 1; i <= n; ++i) {
        int cnt ,value ,num = 0;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            cin >> value;
            num += pow(2,value-1);
        }
        st[i] = num;
    }
    dfs(0,1,0);
    cout << ans;
}