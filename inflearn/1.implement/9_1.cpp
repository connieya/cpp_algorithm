#include "bits/stdc++.h"

using namespace std;
int n;
int arr[50001];



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <=n; j+=i) {
            arr[j] = arr[j]+1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << ' ';
    }
}