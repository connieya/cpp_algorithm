#include "bits/stdc++.h"

using namespace std;

struct cmp {
    bool operator() (const int&a ,const int&b) const {
        return a > b;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int,vector<int> , cmp> pq;
    pq.push(1);
    pq.push(51);
    pq.push(6);
    pq.push(3);
    pq.push(26);
    pq.push(41);
    pq.push(21);
    while (!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << '\n';
    }
    /*
     1
     3
     6
     21
     26
     41
     51
     * */
}