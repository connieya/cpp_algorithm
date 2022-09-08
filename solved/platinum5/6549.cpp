#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

ll arr[100001];
ll lf[100001];
ll rt[100001];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1){
        int t;
        cin >> t;
        if(!t) break;
        for (int i = 0; i < t; ++i) {
            cin >> arr[i];
        }
        vector<int> s;
        for (int i = 0; i < t; ++i) {
            while (!s.empty() && arr[s.back()] >= arr[i]){
                s.pop_back();
            }
            lf[i] = s.empty() ? -1 : s.back();
            s.push_back(i);

        }
        s.clear();
        for (int i = t-1; i  >=0 ; --i) {
            while (!s.empty() && arr[s.back()] >= arr[i]){
                s.pop_back();
            }
            rt[i] = s.empty() ? t : s.back();
            s.push_back(i);
        }
        ll ans = 0;
        for (int i = 0; i < t; ++i) {
            ans = max(ans , arr[i]*(rt[i]-lf[i]-1));
        }
        cout << ans << '\n';
    }
}