#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , value;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        if (value){
            pq.push(value);
        }else {
            if (pq.size()){
                cout << pq.top() << '\n';
                pq.pop();
            }else{
                cout << 0 << '\n';
            }
        }

    }
}