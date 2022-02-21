#include "bits/stdc++.h"

using namespace std;

void func(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    func(6 - a - b, b, n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    string answer = to_string(pow(2, k));
    int idx = answer.find('.');
    answer = answer.substr(0, idx);
    answer[answer.length() - 1] -= 1;
    cout << answer.c_str() << '\n';
    if (k <= 20) {
        func(1, 3, k);
    }
}