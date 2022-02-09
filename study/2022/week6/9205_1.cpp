#include "bits/stdc++.h"

using namespace std;

int calc_manhattan(pair<int ,int> a , pair<int ,int > b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int ,int>> V;
        bool floyd[102][102];
        for (int i = 0; i < n + 2; ++i) {
            int a ,b;
            cin >> a >> b;
            V.push_back({a,b});
            fill(floyd[i] ,floyd[i]+103, false);
        }
        for (int i = 0; i < n + 2; ++i) {
            for (int j = i+1; j < n+2; ++j) {
                if(calc_manhattan(V[i],V[j]) <= 1000) {
                    floyd[i][j] = true;
                    floyd[j][i] = true;
                }
            }
        }
        for (int k = 0; k < n + 2; ++k) {
            for (int i = 0; i < n + 2; ++i) {
                for (int j = 0; j < n + 2; ++j) {
                    if(floyd[i][k] && floyd[k][j]) {
                        floyd[i][j] = true;
                    }
                }
            }
        }
        string answer = floyd[0][n+1] ? "happy" : "sad";
        cout << answer << '\n';
    }
}