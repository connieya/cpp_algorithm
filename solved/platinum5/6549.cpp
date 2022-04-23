#include "bits/stdc++.h"

#define INF 100001
typedef long long ll;

using namespace std;

ll arr[INF];
int Left[INF];
int Right[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int size;
    while (1) {
        ll ans = -1;
        cin >> size;
        vector<pair<int, int>> stack;
        if (!size) break;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
            while (!stack.empty() && stack.back().second >= arr[i]) {
                stack.pop_back();
            }
            Left[i] = stack.empty() ? -1 : stack.back().first;
            stack.push_back({i, arr[i]});
        }
        stack.clear();
        for (int i = size - 1; i >= 0; --i) {
            while (!stack.empty() && stack.back().second >= arr[i]) {
                stack.pop_back();
            }
            Right[i] = stack.empty() ? size : stack.back().first;
            stack.push_back({i, arr[i]});
        }
        stack.clear();
        for (int i = 0; i < size; ++i) {
            ll t = arr[i] * (Right[i] - Left[i] - 1);
            ans = max(ans, t);
        }
        cout << ans << '\n';

    }
}