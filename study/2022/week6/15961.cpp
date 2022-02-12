#include "bits/stdc++.h"

using namespace std;
int check[3001];
int n , d , k , c;
vector<int> belt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 1;
    int MX =0;
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        belt.push_back(v);
    }
    check[c]++;
    for (int i = 0; i < k; ++i) {
        belt.push_back(belt[i]);
        check[belt[i]]++;
        if (check[belt[i]] == 1){
            ans++;
        }
    }
    int lt =0;
    int rt = k-1;
    while (lt < n){
        check[belt[lt]]--;
        if (check[belt[lt++]] ==0) ans--;
        check[belt[++rt]]++;
        if (check[belt[rt]] == 1) ans++;
        MX = max(MX , ans);
    }
    cout << MX;
}