#include "bits/stdc++.h"

using namespace std;

int arr[2001];
bool palindrome[2001][2001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        palindrome[i][i] = true;
        if (i < n && arr[i] == arr[i+1]){
            palindrome[i][i+1] = true;
        }
    }
    for (int i = n-1; i >= 1; --i) {
        for (int j = i+2; j <= n; ++j) {
            if (arr[i] == arr[j] && palindrome[i+1][j-1]){
                palindrome[i][j] = true;
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int start , end;
        cin >> start >> end;
        cout << palindrome[start][end] << '\n';
    }
}