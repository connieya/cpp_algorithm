#include "bits/stdc++.h"
using namespace std;

bool visited[100001];
int money[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
        cin >> money[i];
        visited[money[i]] = true;
        Q.push(money[i]);
    }
    int L = 1;
    while (!Q.empty()){
        int len = Q.size();
        for (int i = 0; i < len; ++i) {
            int coin = Q.front();
            Q.pop();
            if (coin == k){
                cout << L;
                exit(0);
            }
            for (int j = 0; j < n; ++j) {
                if (coin+money[j] > k) continue;
                if (!visited[coin+money[j]]){
                    visited[coin+money[j]] = true;
                    Q.push(coin+money[j]);
                }
            }

        }
        L++;
    }
    cout << -1;
}