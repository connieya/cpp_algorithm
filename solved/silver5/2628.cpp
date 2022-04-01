#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> garo;
    vector<int> sero;
    garo.push_back(0);
    sero.push_back(0);
    garo.push_back(m);
    sero.push_back(n);
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        if (a) {
            sero.push_back(b);
        } else {
            garo.push_back(b);
        }
    }
    sort(sero.begin(), sero.end());
    sort(garo.begin(), garo.end());
    int garo_max = 0;
    int sero_max = 0;
    for (int i = 1; i < garo.size(); ++i) {
        if (garo[i] - garo[i - 1] > garo_max) {
            garo_max = garo[i] - garo[i - 1];
        }
    }
    for (int i = 1; i < sero.size(); ++i) {
        if (sero[i] - sero[i - 1] > sero_max) {
            sero_max = sero[i] - sero[i - 1];
        }
    }
    cout << garo_max*sero_max;
}