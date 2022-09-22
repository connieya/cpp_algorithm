#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,num ,info;
    cin >> n;
    vector<int> arr(11,-1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num >> info;
        if(arr[num] == -1){
            arr[num] = info;
            continue;
        }
        if(arr[num] != info){
            ans++;
            arr[num] = info;
        }
    }
    cout << ans;
}