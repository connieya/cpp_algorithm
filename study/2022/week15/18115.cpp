#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin >> n;
    vector<int> v;
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
    reverse(v.begin(),v.end());
    for (int i = 1; i <= n; ++i) {
        if (v[i-1] == 1){
            dq.push_front(i);
        }else if (v[i-1] == 2){
            int a = dq.front();
            dq.pop_front();
            dq.push_front(i);
            dq.push_front(a);
        }else {
            dq.push_back(i);
        }
    }
    while (!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }

}