#include "bits/stdc++.h"

#define MAX 100001

using namespace std;

vector<pair<int, int>> tree[MAX];
int c = -1;
int endpoint;
void dfs(int start ,int prev , int sum){
    if (sum > c){
        c = sum;
        endpoint = start;
    }

    for (auto next: tree[start]) {
        if (next.first != prev){
            dfs(next.first,start,sum+next.second);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, node,a , cost;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node;
        while (1) {
            cin >> a;
            if (a == -1) break;
            cin >> cost;
            tree[node].push_back({a,cost});
        }
    }
    dfs(1,1,0);
    c= -1;
    dfs(endpoint,endpoint,0);
    cout << c;


}