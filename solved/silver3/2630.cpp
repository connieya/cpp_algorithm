#include "bits/stdc++.h"

using namespace std;

int arr[129][129];
int white = 0 , blue = 0;

void divide_conquer(int x,int y ,int n){
    int val = arr[x][y];
    for (int i = x; i <n+x; ++i) {
        for (int j = y; j < n+y; ++j) {
            if (val != arr[i][j]){
                val = -1;
                break;
            }
            if (val == -1) break;
        }
    }
    if (val == 0) {
        white++;
    }else if (val == 1) {
        blue++;
    } else if (val == -1) {
        divide_conquer(x,y,n/2);
        divide_conquer(x+n/2,y+n/2,n/2);
        divide_conquer(x,y+n/2,n/2);
        divide_conquer(x+n/2,y,n/2);
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
    divide_conquer(0,0,n);
    cout << white <<'\n' << blue;

}