#include "bits/stdc++.h"

using namespace std;

int dfs(string &str, int index, char prev) {
    if (str.length() == index) {
        return 1;
    }
    char start = str[index] == 'c' ? 'a' : '0';
    char end = str[index] == 'c' ? 'z' : '9';
    int ans = 0;
    for (int i = start; i <= end; ++i) {
        if (prev != i) {
            ans += dfs(str, index + 1, i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    cout << dfs(str, 0, ' ');

}