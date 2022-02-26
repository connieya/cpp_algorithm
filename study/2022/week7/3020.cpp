#include "bits/stdc++.h"

using namespace std;

int bottom[100001];
int top[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,h;
    cin >> n >> h;
    for (int i = 0; i < n/2; ++i) {
        cin >> bottom[i] >> top[i];
    }
    sort(bottom,bottom+n/2);
    sort(top,top+n/2);
    int ans = 21470000;
    int num = 0;
    for (int i = 1; i <= h; ++i) {
        int cnt = 0;
        int idx = lower_bound(bottom,bottom+n/2,i)-bottom;
        cnt += n/2-idx;

        idx = upper_bound(top,top+n/2 , h-i)-top;
        cnt += n/2-idx;

        if (ans == cnt){
            num++;
        } else if (ans > cnt){
            ans = cnt;
            num = 1;
        }
    }
    cout << ans << ' ' << num;
}