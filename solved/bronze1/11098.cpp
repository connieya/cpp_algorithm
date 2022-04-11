#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t , n  ,price;
    string name;
    cin >> t;
    while (t--) {
        cin >> n;
        int max_price = -1;
        string ans = "";
        for (int i = 0; i < n; ++i) {
            cin >> price >> name;
            if (price > max_price){
                max_price = price;
                ans = name;
            }
        }
        cout << ans << '\n';
    }
}