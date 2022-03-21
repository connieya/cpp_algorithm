#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n , k;
        cin >> n >> k;
        queue<pair<int,int>> Q;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            Q.push({num,i});
        }
        int cnt = 1;
        while (!Q.empty()){
            int cur = Q.front().first;
            int index = Q.front().second;
            Q.pop();
            int len = Q.size();
            bool flag = false;
            for (int i = 0; i < len; ++i) {
                int nxt = Q.front().first;
                int idx = Q.front().second;
                if (nxt > cur){
                    flag = true;
                }
                Q.pop();
                Q.push({nxt,idx});
            }
            if (flag) {
                Q.push({cur,index});
            }else {
                if (index == k) break;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}