#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string name;
    cin >> n >> m;
    vector<string> a, b;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        a.push_back(name);
    }
    for (int i = 0; i < m; ++i) {
        cin >> name;
        b.push_back(name);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<string> answer;
    for (int i = 0, j = 0; i < a.size() && j < b.size();) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            answer.push_back(a[i]);
            i++;
            j++;
        }
    }
    cout << answer.size() << '\n';
    for (auto s: answer) {
        cout << s << '\n';
    }
}