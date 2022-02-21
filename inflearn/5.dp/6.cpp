#include "bits/stdc++.h"

using namespace std;

struct Brick {
    int width, height, weight;

    Brick(int w, int h, int we) {
        width = w;
        height = h;
        weight = we;
    }

    bool operator<(const Brick &b) const {
        return width > b.width;
    }
};

int dp[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<Brick> bricks;
    for (int i = 0; i < n; ++i) {
        int width, height, weight;
        cin >> width >> height >> weight;
        bricks.push_back(Brick(width, height, weight));
    }
    sort(bricks.begin(), bricks.end());
    int len = bricks.size();
    for (int i = 0; i < len; ++i) {
        dp[i] = bricks[i].height;
        for (int j = i-1; j >= 0; --j) {
            if (bricks[i].weight < bricks[j].weight){
                dp[i] = max(dp[i] , dp[j]+bricks[i].height);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = max(ans , dp[i]);
    }
    cout << ans;

}