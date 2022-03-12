#include "bits/stdc++.h"

using namespace std;

struct trip {
    int walk_t, walk_c, bicycle_t, bicycle_c;

    trip(int wt ,int wc ,int bt ,int bc){
        walk_t = wt;
        walk_c = wc;
        bicycle_t = bt;
        bicycle_c = bc;
    }

};

int n,k , ans = -1;
vector<trip> T;
int dp[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int wt, wc, bt, bc;
        cin >> wt >> wc >> bt >> bc;
        T.push_back(trip(wt,wc,bt,bc));
    }

    for (int i = 1; i < n; ++i) {
        int w_time = T[i].walk_t;
        int w_cost = T[i].walk_c;
        int b_time = T[i].bicycle_t;
        int b_cost = T[i].bicycle_c;

    }
    cout << ans;
}