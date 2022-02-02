#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[100000];
    int n,t=1;
    long ans = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr,arr+n);

    for(int i = 0; i < n; i++){
        if(arr[i] >= t){
            ans+=arr[i]-t;
            t++;
        }
    }
    cout << ans;
}