#include "bits/stdc++.h"

using namespace std;

int arr[2200][2200];
int paper[3];

void dq(int x ,int y , int n) {
    int val = arr[x][y];

    for (int i = x; i < n+x; ++i) {
        for (int j = y; j < n+y; ++j) {
            if (arr[i][j] != val){
                val= 2;
                break;
            }
        }
        if (val == 2) break;
    }
    if (val == -1) {
        paper[0]++;
    } else if (val == 0){
        paper[1]++;
    }else if (val == 1) {
        paper[2]++;
    }else {
        dq(x,y,n/3); // (0,0)
        dq(x+n/3,y,n/3); // (3,0)
        dq(x,y+n/3,n/3); // (0,3)
        dq(x+n/3,y+n/3,n/3);// (3,3)
        dq(x+n/3+n/3,y,n/3); // (6,0)
        dq(x+n/3+n/3,y+n/3,n/3); // (6,3)
        dq(x,y+n/3+n/3,n/3); // (0,6)
        dq(x+n/3,y+n/3+n/3,n/3); // (3,6)
        dq(x+n/3+n/3,y+n/3+n/3,n/3); // (6,6)
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    dq(0,0,n);
    cout << paper[0] << '\n';
    cout << paper[1] << '\n';
    cout << paper[2] << '\n';
}