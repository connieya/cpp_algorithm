#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,v, ans = 0;
    cin >> n;
    int lookup[7] = {0,};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> v;
            lookup[v]++;
        }
        int mx = 0;
        int money = 0;
        bool flag = true;
        for (int j = 1; j <=6; ++j) {
            if(!lookup[j]) continue;
            if(lookup[j] == 3){
                mx = j;
                money = 10000+j*1000;
                flag =false;
                break;
            }else if(lookup[j] == 2){
                mx = j;
                money = 1000+j*100;
                flag =false;
                break;
            }else {
                mx = max(mx,j);
            }
        }
        if(flag){
            money = mx*100;
        }
        ans = max(ans,money);
        memset(lookup , 0 , sizeof(lookup));
    }
    cout << ans;
}