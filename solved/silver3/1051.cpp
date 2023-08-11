﻿#include "bits/stdc++.h"

using namespace std;

int board[51][51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string str;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); ++j) {
            board[i][j] = str[j] - '0';
        }
    }

    int ans = 1;
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            int mn = min(i,j);
            for(int k=1; k<=mn; k++){
                if(board[i][j] == board[i-k][j] && board[i-k][j] == board[i][j-k] && board[i-k][j] == board[i-k][j-k]){
                    ans = max(ans , (k+1)*(k+1));
                }
            }
        }
    }
    cout << ans;
}