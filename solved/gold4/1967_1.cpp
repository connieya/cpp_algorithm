#include "bits/stdc++.h"
#define MAX 10001

using namespace std;

vector<pair<int,int>> tree[MAX];
int cost[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , res = 0;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int parent , child , edge;
        cin >> parent >> child >> edge;
        tree[child].push_back({parent,edge});
    }
    for (int i = n; i > 0; --i) {
        int len = tree[i].size();
        for (int j = 0; j < len; ++j) {
            int p =  tree[i][j].first;
            int e = tree[i][j].second;
            if (cost[p]+cost[i]+e > res){
                res = cost[p]+cost[i] +e;
            }
            if (cost[i]+e > cost[p]){
                cost[p] = cost[i]+e;
            }
        }
    }
    cout << res;
}