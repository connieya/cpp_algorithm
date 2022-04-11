#include "bits/stdc++.h"

using namespace std;

bool isPattern(int first, int second, string numbers) {
    int temp = second;
    while (first < temp) {
        if (numbers[first++] != numbers[second++]) return false;
    }
    return true;
}

void solve(int j, int n, string numbers) {
    int ans = 0;
    for (int i = 0; i < j; ++i) {
        ans += (numbers[i] - '0');
    }
    ans *= n / j;
    for (int i = 0; i < n % j; ++i) {
        ans += (numbers[i] - '0');
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string numbers;
    int n;
    cin >> numbers >> n;
    int len = numbers.size();
    int j;
    for (j = 3; j < len; ++j) {
        if (numbers[0] == numbers[j] && isPattern(0, j, numbers)) {
            break;
        }
    }
    solve(j, n, numbers);
}