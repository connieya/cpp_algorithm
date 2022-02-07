#include "bits/stdc++.h"

using namespace std;

int arr[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , up_cnt = 0, down_cnt =0 ,up_idx = 0, down_idx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; ++i) {
       if(arr[i-1] < arr[i]){
           up_cnt++;
           up_idx = i;
       }
       if(arr[i-1] > arr[i]) {
           down_cnt++;
           down_idx = i;
       }
    }
    if(up_cnt == n-1) {
        cout << 0;
        exit(0);
    }
    if(down_cnt == n-1){
        cout << ;
        exit(0);
    }


}