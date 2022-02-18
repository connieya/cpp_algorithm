#include "bits/stdc++.h"

using namespace std;

struct Time {
    int st ,en , v;
    Time(int s ,int e ,int vv){
        st = s;
        en = e;
        v = vv;
    }
    bool operator<(const Time &t)const{
        return en < t.en;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,r;
    cin >> n >> m >> r;
    vector<Time> time;
    vector<int> dp(m+1,0);
    for (int i = 0; i < m; ++i) {
        int st , en , v;
        cin >> st >>en >> v;
        time.push_back(Time(st,en,v));
    }
    sort(time.begin(),time.end());
    for (int i = 0; i < m; ++i) {
        dp[i] = time[i].v;
        for (int j = i-1; j >=0; --j) {
            if (time[i].st >= time[j].en + r) {
                dp[i] = max(dp[i] , dp[j]+time[i].v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = max(ans ,dp[i]);
    }
    cout << ans;


}