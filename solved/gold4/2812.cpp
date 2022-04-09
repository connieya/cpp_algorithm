#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;
    int len = input.size();
    string S;
    for (int i = 0; i < len; ++i) {
        while (!S.empty() && S.back() < input[i] && k) {
            k--;
            S.pop_back();
        }
        S.push_back(input[i]);

    }
    while (k) {
        S.pop_back();
        k--;
    }
    cout << S;
}