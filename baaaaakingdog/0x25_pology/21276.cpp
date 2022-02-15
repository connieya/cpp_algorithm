#include "bits/stdc++.h"

using namespace std;

string people[1001];
string a, b;
unordered_map<string, int> mp;
unordered_map<string, int> f;
vector<string> family[1001];
vector<string> res;
vector<string> answer[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> Q;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
        f[people[i]] = i;
    }
    sort(people, people + n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        int son = f[a];
        int parent = f[b];
        mp[a]++;
        family[parent].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (mp[people[i]] == 0) {
            int ancestor = f[people[i]];
            Q.push(ancestor);
            res.push_back(people[i]);
        }
    }
    cout << res.size() << '\n';
    for (string r: res) {
        cout << r << ' ';
    }
    cout << '\n';
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (string child : family[now]) {
            mp[child]--;
            if (mp[child] == 0) {
                Q.push(f[child]);
                answer[now].push_back(child);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int key = f[people[i]];
        cout << people[i] << ' ' << answer[key].size() << ' ';
        for (string a: answer[key]) {
                cout << a << ' ';
        }
        cout <<'\n';
    }
}