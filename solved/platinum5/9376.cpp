#include "bits/stdc++.h"

using namespace std;

char prison[101][101];
int h, w;
vector<pair<int,int>> path;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> prison[i];
    }
    for (int i = 0; i < h; ++i) {
        if (prison[i][0] == '.' || prison[i][0] == '#'){
            path.push_back({i,0});
        }
        if (prison[i][w-1] == '.' || prison[i][w-1] == '#'){
            path.push_back({i,w-1});
        }
    }
    for (int i = 1; i <w-2 ; ++i) {
    }


}