#include "bits/stdc++.h"

using namespace std;

int arr[100001];

void solve(int op, int s , int c){
    if (op == 1){
        arr[s] |= 1 << c;
        return;
    }
    arr[s] &= ~(1<<c);
}

void moveSeat(int op , int s){
    if (op == 3){
        arr[s] = arr[s] << 1;
        arr[s] &= ((1 << 21) - 1);
        return;
    }
    arr[s] = arr[s] >> 1;
    arr[s] &= ~1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,op,s,c;
    cin >> n >> m;
    unordered_map<int,bool> MP;
    for (int i = 0; i < m; ++i) {
        cin >> op;
        if (op <=2) {
            cin >> s >> c;
            solve(op,s,c);
        }else {
            cin >> s;
            moveSeat(op,s);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!MP[arr[i]]){
            ans++;
            MP[arr[i]] = true;
        }
    }
    cout << ans;
}