#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin() , numbers.end());
    int lt = 0 , rt = 1;
    int sub = 0;
    int ans = INT_MAX;
    while (rt < n) {
        sub = numbers[rt] - numbers[lt];
        if (sub < m) {
            rt++;
        }else {
            ans = min(ans,sub);
            lt++;
        }
        if (ans == m) break;
    }
    cout << ans;
}