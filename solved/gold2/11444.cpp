#include "bits/stdc++.h"

#define INF 1000000007
typedef long long ll;
using namespace std;

vector<vector<ll>> a = {{1, 1},
                        {1, 0}};

vector<vector<ll>> matrix(vector<vector<ll>> b, vector<vector<ll>> c) {
    vector<vector<ll>> res(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                res[i][j] += (b[i][k] * c[k][j]) % INF;
            }
            res[i][j] %= INF;
        }
    }
    return res;
}

vector<vector<ll>> fibo(ll n) {
    if (n == 1 || n == 0) return a;
    vector<vector<ll>> ans = fibo(n / 2);
    ans = matrix(ans, ans);
    if (n % 2) {
        return matrix(a, ans);
    } else {
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> r = fibo(n);
    cout << r[1][0] % INF;
}