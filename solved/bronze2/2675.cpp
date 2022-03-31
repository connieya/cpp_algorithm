#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    string input;
    cin >> t;
    while (t--) {
        cin >> n >> input;
        for (int i = 0; input[i]; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << input[i];
            }
        }
        cout << '\n';
    }
}