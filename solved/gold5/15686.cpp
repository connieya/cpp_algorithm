#include "bits/stdc++.h"

using namespace std;


int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int,int>> person;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >>  m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                chicken.push_back({i, j});
            }else if(arr[i][j] == 1){
                person.push_back({i,j});
            }
        }
    }
    vector<int> d(chicken.size());
    for (int i = 0; i < m; ++i) {
        d[i] = 1;
    }
    sort(d.begin(),d.end());
    int ans = INT_MAX;
    do {
        int sum = 0;
        for(auto p : person){
            vector<int> dist;
            for (int i = 0; i < chicken.size(); ++i) {
                if(!d[i]) continue;
                dist.push_back(abs(chicken[i].first-p.first)+ abs(chicken[i].second-p.second));
            }
            sum += *min_element(dist.begin(),dist.end());
        }
        if(ans > sum) ans = sum;
    } while (next_permutation(d.begin(),d.end()));

    cout << ans;
}