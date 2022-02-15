#include "bits/stdc++.h"

using namespace std;

int arr[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int move = arr[1];
    arr[1] = 0;
    int cnt = 1;
    int idx = 1;
    cout << 1 << ' ';
    while (cnt < n){
        if (move > 0){
            while (move){
                idx++;
                if (idx > n){
                    idx = 1;
                }
                if (arr[idx] != 0){
                    move--;
                }
            }
        }else {
            while (move < 0){
                idx--;
                if (idx == -1){
                    idx = n;
                }
                if (arr[idx] != 0){
                    move++;
                }
            }
        }
        cout << idx << ' ';
        move = arr[idx];
        arr[idx] = 0;
        cnt++;
    }
}