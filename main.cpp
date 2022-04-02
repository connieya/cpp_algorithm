#include "bits/stdc++.h"
#define INF 1000000
using namespace std;

int arr[11][11];
int perm[11];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (!arr[i][j]){
                arr[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }
    do {
        int sum = 0;
        int i;
        for (i = 0; i < n-1; ++i) {
            sum += arr[perm[i]][perm[i+1]];
        }
        sum += arr[perm[i]][perm[0]];
        if (sum < ans){
            ans = sum;
        }
    } while (next_permutation(perm,perm+n));
    cout << ans;
}