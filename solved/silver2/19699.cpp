#include "bits/stdc++.h"

using namespace std;

int n,m;
int cows[10];
bool prime[10000];
bool visited[10000];
vector<int> ans;

void init() {
    prime[1] = true;
    for (int i = 2; i*i <=9999 ; ++i) {
        if (prime[i]) continue;
        for (int j = i*i; j <= 9999; j+=i) {
            prime[j] = true;
        }

    }
}

void dfs(int L , int start , int sum){
    if (L == m){
        if (!prime[sum] && !visited[sum]) {
            visited[sum] = true;
            ans.push_back(sum);
        }
        return;
    }
    for (int i = start; i < n; ++i) {
        sum += cows[i];
        dfs(L+1,i+1 ,sum);
        sum -= cows[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    init();
    dfs(0,0,0);
    if (ans.size() == 0){
        cout << -1;
    }else {
        sort(ans.begin(),ans.end());
        for (int a : ans ) {
            cout << a << ' ';
        }
    }

}