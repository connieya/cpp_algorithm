#include "bits/stdc++.h"

using namespace std;

int a[51][51];
int b[51][51];

void reverse(int x , int y) {
    for (int i = x; i <= x+2; ++i) {
        for (int j = y; j <= y+2; ++j) {
            a[i][j] = 1-a[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,ans =0;
    string input;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        int len = input.size();
        for (int j = 0; j < len; ++j) {
            a[i][j] = input[j]-'0';
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> input;
        int len = input.size();
        for (int j = 0; j < len; ++j) {
            b[i][j] = input[j]-'0';
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            if (a[i][j] != b[i][j]){
                ans++;
                reverse(i,j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]){
                ans = -1;
                break;
            }
        }
    }
    cout << ans;
}