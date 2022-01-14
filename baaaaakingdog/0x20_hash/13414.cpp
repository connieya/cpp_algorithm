#include "bits/stdc++.h"

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k,l;
    unordered_map<string ,int > hash;
    cin >> k >> l;
    string num;
    queue<pair<string,int>> Q;
    for (int i = 0; i < l; ++i) {
        cin >> num;
        Q.push({num,i});
        if (hash.find(num) != hash.end()) { // 수강 신청 한번 더 했다면
            hash[num] = i;
        } else { // 처음 신청했다면
            hash[num] = i;
        }
    }
    int cnt = 0;
    while (!Q.empty()) {
        string x = Q.front().first;
        int idx = Q.front().second;
        Q.pop();
        if (hash[x] == idx) {
            cout << x << '\n';
            cnt++;
        }
        if (cnt == k) break;
    }
}