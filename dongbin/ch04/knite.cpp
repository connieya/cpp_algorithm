#include "bits/stdc++.h"

using namespace std;

int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {-1,1,2,2,1,-1,-2,-2};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char str[3];
    cin >> str;
    int x = str[0]-'a'+1;
    int y = str[1]-'0';
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >=1 && nx<=8 && ny>=1 && ny <= 8 ) {
            cnt++;
        }
    }
    cout << cnt;
}