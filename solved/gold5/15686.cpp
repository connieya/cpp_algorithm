#include "bits/stdc++.h"

using namespace std;
int n,r;
bool visited[50];
vector<pair<int ,int>> comp;
vector<pair<int ,int>> city;
int res = 2145000;

void dfs(int L , int start){
    if (L == r) {
        int sum = 0;
        for (int i = 0; i < city.size(); ++i) {
            auto city_dis = city[i];
            int MIN = 2147000;
            for (int j = 0; j < comp.size(); ++j) {
                if (visited[j]) {
                    auto chicken = comp[j];
                    int dis = abs(city_dis.first-chicken.first) + abs(city_dis.second-chicken.second);
                    MIN = min(MIN , dis);
                }
            }
            sum += MIN;
        }
        res = min(res ,sum);
        return;
    }
    for (int i = start; i < comp.size(); ++i) {
        visited[i] = true;
        dfs(L+1,i+1);
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            if (tmp == 1){
                city.push_back({i,j}); continue;
            }
            if (tmp == 2){
                comp.push_back({i,j});
            }
        }
    }
    dfs(0,0);
    cout << res;
}