#include "bits/stdc++.h"

using namespace std;

int arr[200001];

int countWifi(int num , int n) {
    int cnt = 1;
    int locate  = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i]-locate >= num) {
            locate = arr[i];
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k , ans;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int lt = 1;
    int rt = arr[n-1]-arr[0];
    while (lt <= rt) {
        int mid_distance = (lt+rt) /2;
        if (countWifi(mid_distance, n) >= k){ // 공유기 설치 가 많다 최소거리 늘림
            lt = mid_distance+1;
            ans = mid_distance;
        }else { // 공유기 설치하는 개수가 적다 , 기준이 되는 최소 거리가 줄여라
            rt = mid_distance-1;
        }
    }
    cout << ans;
}