#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    stack<pair<char, int>> S;
    int sum = 0;
    for (char ch: str) {
        if (ch == ')') {
            while (1) {
                if (S.top().first == '(') {
                    S.pop();
                    S.top().second = (S.top().first - 48) * sum;
                    sum = 0;
                    break;
                }
                sum += S.top().second;
                S.pop();
            }

        } else {
            S.push({ch, 1});
        }
    }
    int ans = 0;
    while (!S.empty()){
        ans += S.top().second;
        S.pop();
    }
    cout << ans;
}