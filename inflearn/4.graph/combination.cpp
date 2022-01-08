#include "bits/stdc++.h"

using namespace std;

int n,r;
int arr[8];
int ch[8];

void dfs(int start ,int l){
    if (l == r){
        for (int i = 0; i < r; ++i) {
            cout << ch[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; ++i) {
        ch[l] = i;
        dfs(i+1,l+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    dfs(0,0);
}