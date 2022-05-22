#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto cmp = [](const int &a, const int &b) {
        return a > b;
    };
    priority_queue<int, vector<int> , decltype(cmp)> pq(cmp);
    pq.push(1);
    pq.push(2);
    pq.push(24);
    pq.push(5);
    pq.push(25);
    pq.push(6);
    while (pq.size()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << '\n';
    }
    /*
     1
     2
     5
     6
     24
     25
     * */

}

