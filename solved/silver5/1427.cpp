#include "bits/stdc++.h"

using namespace std;

int digits[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n) {
        digits[n%10]++;
        n /= 10;
    }
    for (int i = 9; i >=0; --i) {
        int d = digits[i];
        for (int j = 0; j < d; ++j) {
            cout << i;
        }
    }

}