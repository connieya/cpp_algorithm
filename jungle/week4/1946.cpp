#include "bits/stdc++.h"

using namespace std;
typedef pair<int,int> p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<p> score;
        for (int i = 0; i < n; ++i) {
            int a,b;
            cin >> a >> b;
            score.push_back({a,b});
        }
        sort(score.begin(), score.end());
//        for (auto s : score) {
//            cout << s.first << " " << s.second << '\n';
//        }
        int len = score.size();
        int ans = 1;
        int prev = score[0].second;
        for (int i = 1; i < len; ++i) {
            if (score[i].second < prev){
                ans++;
            }
            prev = min(prev,score[i].second);
        }
        cout << ans << '\n';
    }
}