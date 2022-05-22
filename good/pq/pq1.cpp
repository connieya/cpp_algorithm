#include "bits/stdc++.h"

using namespace std;

struct Info {
    int val;
    bool operator< (const Info &i) const {
        return val > i.val;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<Info> pq;
    pq.push(Info{1});
    pq.push(Info{21});
    pq.push(Info{31});
    pq.push(Info{11});
    pq.push(Info{12});
    pq.push(Info{4});
    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        cout << cur.val << '\n';
    }
    /*
     1
     4
     11
     12
     21
     31
      */
}