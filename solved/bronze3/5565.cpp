#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int total ,price;
    cin >> total;
    for (int i = 0; i < 9; ++i) {
        cin >> price;
        total -= price;
    }
    cout << total;
}