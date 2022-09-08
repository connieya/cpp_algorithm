﻿#include "bits/stdc++.h"

using namespace std;

int arr[500001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<pair<int,int>> s;
    long long  ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pair<int,int> p = {arr[i],1};
        while (!s.empty()){
            if(s.top().first <= arr[i]){
                ans += (long long ) s.top().second;
                if(s.top().first == arr[i]){
                    p.second += s.top().second;
                }
                s.pop();
            }else{
                break;
            }
        }
        if(!s.empty()) ans += 1LL;
        s.push(p);
    }
    cout << ans;
}