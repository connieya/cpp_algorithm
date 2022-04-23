#include "bits/stdc++.h"

using namespace std;

int arr[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+9);
    int ans = 1e9;
    do {
        int s1 = arr[0]+arr[1]+arr[2];
        int s2 = arr[3]+arr[4]+arr[5];
        int s3 = arr[6]+arr[7]+arr[8];
        vector<int> res;
        res.push_back(s1);
        res.push_back(s2);
        res.push_back(s3);
        sort(res.begin(),res.end());
        int sub =abs(res[0]-res[2]);
        ans = min(sub,ans);
    } while (next_permutation(arr,arr+9));
    cout << ans;
}