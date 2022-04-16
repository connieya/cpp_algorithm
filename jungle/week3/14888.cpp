#include "bits/stdc++.h"
using namespace std;
int number[12];
int op[4];
int MAX = INT_MIN;
int MIN = INT_MAX;

void dfs(int sum , int L,  int len) {
    if (L == len){
        if (sum > MAX){
            MAX =sum;
        }
        if (sum < MIN){
            MIN = sum;
        }
        return;
    }

    if (op[0] > 0){
        op[0]--;
        dfs(sum+number[L],L+1,len);
        op[0]++;
    }
    if (op[1] > 0){
        op[1]--;
        dfs(sum-number[L],L+1,len);
        op[1]++;
    }
    if (op[2] > 0){
        op[2]--;
        dfs(sum*number[L],L+1,len);
        op[2]++;
    }
    if (op[3] > 0){
        op[3]--;
        dfs(sum/number[L],L+1,len);
        op[3]++;
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
        cin >> number[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
    }
    dfs(number[0],1,n);
    cout << MAX << '\n';
    cout << MIN << '\n';
}
