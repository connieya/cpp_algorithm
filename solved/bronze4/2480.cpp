#include "bits/stdc++.h"

using namespace std;

int arr[7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    arr[a]++,arr[b]++,arr[c]++;
    int cnt = 0, max,ans,two;
    for (int i = 1; i <= 6; ++i) {
        if (arr[i] >= 1){
            cnt++;
            max = i;
            if (arr[i] == 2) {
                two = i;
            }

        }
    }
    if (cnt == 1){
        ans = 10000+max*1000;
    } else if (cnt == 3){
        ans = max*100;
    } else {
        ans = 1000 + two*100;
    }
    cout << ans;
}