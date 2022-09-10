#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    unordered_map<string, string> mp;
    for (int i = 0; i < n; ++i) {
        string name, s;
        cin >> name >> s;
        mp[name] = s;
    }
    vector<string> answer;
    for (auto m: mp) {
        if (m.second == "enter") answer.push_back(m.first);
    }
    sort(answer.begin(), answer.end());
    for (int i = answer.size() - 1; i >= 0; --i) {
        cout << answer[i] << '\n';
    }

}