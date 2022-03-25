#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n ,ans =0;
        cin >> n;
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            pq.push(-num);
        }
        while (pq.size()>1){
            int a = -pq.top();
            int b = -pq.top();
            ans += a+b;
            pq.pop();
            pq.pop();
            pq.push(-(a+b));
        }
        ans += -pq.top();
        cout << ans << '\n';
    }
}