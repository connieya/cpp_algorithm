#include "bits/stdc++.h"

using namespace std;

int box[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string answer = "stable";
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> box[i];
    }

    double value = (double) box[n - 1];
    int cnt = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (box[i] > box[i + 1] + l || box[i] < box[i + 1] - l) {
            answer = "unstable";
            break;
        }
        if (value >= box[i] + l || value <= box[i] - l) {
            answer = "unstable";
            break;
        }
        value = (value * cnt + box[i]) / (cnt + 1);
        cnt++;
    }

    cout << answer;
}