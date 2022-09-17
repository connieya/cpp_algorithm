#include "bits/stdc++.h"

using namespace std;

bool isVisited1[40];
bool isVisited2[40];
bool isVisited3[40];

int dfs(int L, int n) {
    if(L == n){
        return 1;
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if (isVisited1[i] || isVisited2[i + L] || isVisited3[L - i + n - 1]) continue;
        isVisited1[i] = true;
        isVisited2[i + L] = true;
        isVisited3[L-i+n-1] = true;
        dfs(L + 1,n);
        isVisited1[i] = false;
        isVisited2[i + L] = false;
        isVisited3[L-i+n-1] = false;

    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << dfs(0, n);
}