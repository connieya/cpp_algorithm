#include "bits/stdc++.h"
#define INF 21470000;

using namespace std;

int city[201][201];
int total[201];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j =1; j <= n; ++j) {
            if (i==j) continue;
            city[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a ,b ,t;
        cin >> a >> b >>t;
        city[a][b] = t;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (city[i][j] > city[i][k]+city[k][j]) {
                    city[i][j] = city[i][k] + city[k][j];
                }
            }
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        for (int j = 1; j <= n; ++j) {
            total[j] = max(city[c][j]+city[j][c],total[j]);
        }
    }
    vector<int> ans;
    int tmp = INF;
    for (int i = 1; i <=n; ++i) {
        if (total[i] < tmp){
            tmp = total[i];
            ans.clear();
            ans.push_back(i);
        } else if (total[i] == tmp) {
            ans.push_back(i);
        }
    }
    for (int a: ans) {
        cout << a << ' ';
    }
}