#include "bits/stdc++.h"

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int r = (rand() % 15);
        if (r == 13) {
            cout << "'\n' program exit ";
            break;
        }
        cout << r << ' ';
    }

}