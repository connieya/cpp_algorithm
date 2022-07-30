﻿#include "bits/stdc++.h"

using namespace std;

bool isPrime[10001];

void init() {
    for (int i = 2; i * i <= 9999; i++) {
        if (isPrime[i]) continue;
        for (int j = i * i; j <= 9999; j += i) {
            isPrime[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string a,b;
    cin >> t;
    init();
    while (t--) {
        cin >> a >> b;
        vector<int> dist(10000,-1);
        queue<int> q;
        bool flag = true;
        dist[stoi(a)] = 0;
        q.push(stoi(a));
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            auto cr = to_string(cur);
            if(cr == b){
                cout << dist[cur] << '\n';
                flag = false;
                break;
            }
            for(int i=0; i<4; i++){
                for(int j=0; j < 10; j++){
                    if(!i && !j) continue;
                    auto nxt = cr;
                    nxt[i] = j+'0';
                    int _nxt = stoi(nxt);
                    if(isPrime[_nxt] || dist[_nxt] != -1) continue;
                    dist[_nxt] = dist[cur]+1;
                    q.push(_nxt);
                }
            }

        }
        if(flag){
            cout << "Impossible\n";
        }
    }
}