#include "bits/stdc++.h"

using namespace std;

bool prime[4000001];

void init(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (prime[i]) continue;
        for (int j = i*i; j <=n; j+=i) {
            prime[j] = true;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n==1){
        cout << 0;
        return 0;
    }
    init(n);
    vector<int> arr;
    for (int i = 2; i <= n; ++i) {
        if (!prime[i]) {
            arr.push_back(i);
        }
    }
    int sum = arr[0];
    int rt = 0;
    int len = arr.size();
    int ans = 0;
    int lt = 0;
    while (rt < len) {
        if (sum < n){
            rt++;
            sum +=arr[rt];
        }else {
            if (sum == n) ans++;
            sum -= arr[lt++];
        }
        if (lt == len) break;
    }
    cout << ans;
}