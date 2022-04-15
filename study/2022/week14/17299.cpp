#include "bits/stdc++.h"

#define INF 1000001
using namespace std;

int number[INF];
int arr[INF];
int ans[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    stack<pair<int, int>> S;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        number[arr[i]]++;
    }
    S.push({0, arr[0]});
    for (int i = 1; i < n; ++i) {
        while (!S.empty() && number[S.top().second] < number[arr[i]]) {
            ans[S.top().first] = arr[i];
            S.pop();
        }
        S.push({i, arr[i]});
    }
    while (!S.empty()) {
        ans[S.top().first] = -1;
        S.pop();
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }


}