#include "bits/stdc++.h"

using namespace std;

int num[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string numbers;
    cin >> numbers;
    int n = 0;
    int len = numbers.length();
    string answer;
    for (int i = 0; i < len; ++i) {
        num[numbers[i] - '0']++;
        n += (numbers[i] - '0');
    }
    if (n % 3 != 0 || num[0] == 0) {
        cout << -1;
        return 0;
    }
    for (int i = 9; i >= 0; --i) {
        while (num[i]) {
            answer += i+'0';
            num[i]--;
        }
    }
    cout << answer;


}