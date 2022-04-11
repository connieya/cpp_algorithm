#include "bits/stdc++.h"

using namespace std;

int dfs(int open, int close, string bracket, int n) {
    if (open > n || close > n || open < close) return 0;
    if (open == n && close == n) {
        cout << bracket << '\n';
        return 1;
    }
    return dfs(open + 1, close, bracket + "(", n) + dfs(open, close + 1, bracket + ")", n);


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << dfs(0, 0, "", n) << '\n';

}