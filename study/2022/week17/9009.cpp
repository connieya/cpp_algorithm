#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> fibo{0,1};
    while (fibo.back() < 1'000'000'000){
        fibo.push_back(fibo.back()+fibo[fibo.size()-2]);
    }
    reverse(fibo.begin(),fibo.end());
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        vector<int> ans;
        for (int i = 0; i < fibo.size() && num; ++i) {
            if (num >= fibo[i]){
                num -= fibo[i];
                ans.push_back(fibo[i]);
            }
        }
        sort(ans.begin(), ans.end());
        for (int a: ans) {
            cout << a << ' ';
        }
        cout << '\n';

    }
}