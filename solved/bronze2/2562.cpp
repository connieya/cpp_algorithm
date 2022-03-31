#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int MX = 0, index = 0 , num;
    for (int i = 0; i < 9; ++i) {
        cin >> num;
        if (num > MX) {
            MX = num;
            index = i+1;
        }
    }
    cout << MX << '\n' << index;
}