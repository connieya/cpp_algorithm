#include "bits/stdc++.h"

using namespace std;

int perm[11];
int arr[12];
int op[4];
int n,a = INT_MAX , b = INT_MIN;
void dfs(int L , int sum) {
    if (L == n) {
        if (sum < a){
            a = sum;
        }
        if (sum > b) {
            b = sum;
        }
        return;
    }
    if (perm[L-1] == 0){
        dfs(L+1,sum+arr[L]);
    } else if (perm[L-1] == 1){
        dfs(L+1,sum-arr[L]);
    }else if(perm[L-1] == 2) {
        dfs(L+1,sum*arr[L]);
    }else {
        dfs(L+1,sum/arr[L]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int j =0;
    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
        while (op[i] > 0) {
            perm[j++] = i;
            op[i]--;
        }
    }
    do {
        dfs(1,arr[0]);
    } while (next_permutation(perm,perm+n-1));
    cout << b << '\n' << a;


}