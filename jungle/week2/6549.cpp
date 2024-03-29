﻿#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

ll arr[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    while (1){
        cin >> t;
        if (!t) break;
        ll ans = 0;
        stack<ll> stack;
        for (int i = 0; i < t; ++i) {
            cin >> arr[i];
            while (!stack.empty() && arr[stack.top()] > arr[i]){
                ll height = arr[stack.top()];
                stack.pop();
                ll width = i;
                if(!stack.empty()){
                    width = i - stack.top()-1;
                }
                if(ans < width*height){
                    ans = width*height;
                }

            }
            stack.push(i);
        }
        while (!stack.empty()){
            ll height = arr[stack.top()];
            stack.pop();
            ll width = t;
            if(!stack.empty()){
                width = t-stack.top()-1;
            }
            if(ans < width*height){
                ans = width*height;
            }
        }
        cout << ans << '\n';

    }
}