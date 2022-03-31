#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string input;
    cin >> t;
    while (t--) {
        cin >> input;
        int sum = 0 , num = 1;
        for (int i = 0; input[i]; ++i) {
            if (input[i] == 'O'){
                sum += num++;
            }else {
                num = 1;
            }
        }
        cout << sum << '\n';
    }
}