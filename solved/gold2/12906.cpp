﻿#include "bits/stdc++.h"

using namespace std;
int hanoi[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> stick(3, "");
    vector<string> finish(3, "");
    for (int i = 0; i < 3; ++i) {
        int cnt;
        cin >> cnt;
        string str = "";
        if (cnt) {
            cin >> str;
           for(auto ch : str){
               hanoi[ch-'A']++;
           }
        }
        stick[i] = str;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < hanoi[i]; ++j) {
            finish[i] += (char)('A' + i);
        }
    }
    map<vector<string> , int > depth;
    queue<vector<string>> q;
    q.push(stick);
    depth[stick] = 0;
    while (!q.empty()){
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if( i==j) continue;
                if(now[i].length() ==0) continue;
                vector<string>next =now;
                next[j].push_back(next[i].back());
                next[i].pop_back();
                if(depth.count(next) == 0) {
                    depth[next] = depth[now]+1;
                    q.push(next);
                }
            }
        }
    }
    cout << depth[finish];
}