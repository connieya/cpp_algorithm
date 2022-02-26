#include "bits/stdc++.h"

using namespace std;

int n,d,k;
int res = -1;

void dfs(int L , int start , int bit , vector<int> &st , vector<int> &pow)
{
    if (L==k) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if ( (bit&st[i]) == st[i]){
                cnt++;
            }
        }
        res = max(res, cnt);
        return;
    }
    for (int i = start; i <=d; ++i) {
        dfs(L+1,i+1,bit+pow[i],st,pow);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d >> k;
    vector<int> st(n+1) , pow(d+1);
    pow[1] =1;
    for (int i = 2; i <= d; ++i) {
        pow[i] = pow[i-1]*2;
    }
    for (int i = 1; i <= n; ++i) {
        int cnt , num;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            cin >> num;
            st[i] += pow[num];
        }
    }
    dfs(0,1,0,st,pow);
    cout << res;
}