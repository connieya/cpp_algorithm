#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int answer = 0;
    int target = n;
    do {
        target = (target % 10) * 10 + ((target / 10 + target % 10)) % 10;
        answer++;
    } while (target != n);
    cout << answer;
}