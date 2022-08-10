#include "bits/stdc++.h"

using namespace std;

vector<char> op;
vector<int> num;
int n;
int ans = INT_MIN;

int calc(int a, char op, int b) {
    if (op == '+') return a + b;
    if (op == '*') return a * b;
    return a - b;
}

void dfs(int L, int sum) {
    if (L >= n) {
        if (L == n && sum > ans) {
            ans = sum;
        }
        return;
    }
    dfs(L + 1, calc(sum, op[L] , num[L + 1]));
    dfs(L + 2, calc(sum, op[L] , calc(num[L + 1], op[L+1] ,num[L + 2])));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char ch;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        if (i % 2) {
            op.push_back(ch);
        } else {
            num.push_back(ch - '0');
        }
    }

    n /= 2;
    dfs(0, num[0]);
    cout << ans;
}