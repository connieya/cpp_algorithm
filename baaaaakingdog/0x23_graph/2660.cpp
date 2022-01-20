#include "bits/stdc++.h"
#define INF 1e5
using namespace std;

int member[51][51];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<int> ans;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            member[i][j] = INF;
        }
    }
    while (true){
        int a , b;
        cin >> a >> b;
        if (a+b == -2) break;
        member[a][b] =1;
        member[b][a] =1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                member[i][j] = min(member[i][j] , member[i][k]+member[k][j]);
            }
        }
    }
    int MIN = INF;
    for (int i =1; i <= n; ++i) {
        int score = 0;
        for (int j = 1; j <= n; ++j) {
            score = max(score , member[i][j]);
        }
        if (MIN > score) {
            MIN = score;
            ans.clear();
            ans.push_back(i);
        }else if (MIN == score) {
            ans.push_back(i);
        }
    }
    cout << MIN << ' ' << ans.size() << '\n';
    for (int a : ans) {
        cout << a << ' ';
    }
}