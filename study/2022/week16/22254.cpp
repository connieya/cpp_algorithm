#include "bits/stdc++.h"

using namespace std;

int n, x;
int v[100001];
bool check(int num){
    vector<int> vec(num,0);
    priority_queue<int,vector<int>,greater<int>> pq(vec.begin(),vec.end());
    for (int i = 0; i < n; ++i) {
        int t = pq.top();
        pq.pop();
        if (t+v[i] > x) return false;
        pq.push(t+v[i]);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int lt = 0, rt = n;
    while (lt+1 < rt) {
        int mid = (lt+rt)/2;
        if (check(mid)){
            rt = mid;
        }else {
            lt = mid;
        }
    }
    cout << rt;
}