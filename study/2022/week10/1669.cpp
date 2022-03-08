#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    int c = b - a;
    if (c == 0) {
        cout << 0;
        return 0;
    }
    long long day = 1;

    while (day * day < c) {
        day++;
    }
    if (day * day == c) {
        cout << 2 * day - 1;
    } else {
        day--;
        c -= day * day;
        int answer = 0;
        while (c > 0) {
            c -= day > c ? c : day;
            answer++;
        }
        cout << 2*day-1+answer;
    }
}