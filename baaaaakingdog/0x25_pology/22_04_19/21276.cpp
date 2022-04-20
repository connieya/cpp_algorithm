#include "bits/stdc++.h"

using namespace std;

unordered_map<string, int> mp;
unordered_map<int, string> mp2;
int indegree[1001];
vector<string> v[1001];
vector<string> ans[1001];
string arr[1001];
vector<string> ancestor;
queue<int> Q;

void topology() {
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (string child: v[now]) {
            int c = mp[child];
            indegree[c]--;
            if (indegree[c] == 0) {
                Q.push(c);
                ans[now].push_back(child);
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string s, child, parent;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; ++i) {
        mp[arr[i]] = i;
        mp2[i] = arr[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> child >> parent;
        v[mp[parent]].push_back(child);
        indegree[mp[child]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            Q.push(i);
            ancestor.push_back(mp2[i]);
        }
    }
    topology();
    sort(ancestor.begin(), ancestor.end());
    cout << ancestor.size() << '\n';
    for (string a: ancestor) {
        cout << a << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        sort(ans[i].begin(), ans[i].end());
        cout << mp2[i] << ' ' << ans[i].size() << ' ';
        for (string a: ans[i]) {
            cout << a << ' ';
        }
        cout << '\n';
    }

}