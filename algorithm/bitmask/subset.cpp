#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[] = {4,5,11,34,51};
    for (int i = 1; i < 1<<5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i & (1 << j)) {
                cout << arr[j] << ' ';
            }
        }
        cout << '\n';
    }
}