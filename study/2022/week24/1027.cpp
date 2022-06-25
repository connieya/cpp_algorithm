#include "bits/stdc++.h"

using namespace std;

int arr[51];
int cnt[51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        double mx = -1e9;
        for (int j = i + 1; j < n; ++j) {
            int h = arr[j] - arr[i];
            int w = j - i;
            double g = h * 1.0 / w;

            if (g > mx) {
                mx = g;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    cout << *max_element(cnt, cnt + n);

}