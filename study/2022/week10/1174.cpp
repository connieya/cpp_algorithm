#include "bits/stdc++.h"

using namespace std;

int arr[] = {9,8,7,6,5,4,3,2,1,0};
vector<long long > V;

void dfs(long long sum , int idx) {
    if (idx == 10){
        if (find(V.begin(),V.end(),sum) ==V.end()) {
            V.push_back(sum);
        }
        return;
    }


    dfs(sum*10+arr[idx],idx+1);
    dfs(sum,idx+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    dfs(0,0);
    sort(V.begin(),V.end());
    if (N > 1023) {
        cout << -1;
    }else {
        dfs(0,0);
        cout << V[N-1];
    }
}