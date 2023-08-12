#include "bits/stdc++.h"

using namespace std;

string dp[101][101];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = to_string(i);
        for (int j = 2; j <= i; j++) {
            string a = dp[i - 1][j - 1];
            string b = dp[i - 1][j];
            string c = "";
            bool add = false;
            int x = a.length() - 1;
            int y = b.length() - 1;
            while (x >= 0 && y >= 0) {
                int n1 = a[x] - '0';
                int n2 = b[y] - '0';
                int d;
                if (add) {
                    d = (n1 + n2 + 1) % 10;
                } else {
                    d = (n1 + n2) % 10;
                }
                if(d/10) add = true;
                else add =false;
                c = to_string(d) + c;
                x--;
                y--;
            }
            while (x>=0){
                int d;
                if(add){
                    d = (a[x]-'0')+1;
                }else {
                    d = a[x]-'0';
                }
                if(d/10) add = true;
                else add =false;

                c = to_string(d)+c;
                x--;
            }

            while (y>=0){
                int d;
                if(add){
                    d = (b[y]-'0')+1;
                }else {
                    d = b[y]-'0';
                }
                if(d/10) add = true;
                else add =false;

                c = to_string(d)+c;
                y--;
            }


            if(add){
                c = '1'+c;
            }
            dp[i][j] = c;
        }
    }
    cout << dp[n][m];

}