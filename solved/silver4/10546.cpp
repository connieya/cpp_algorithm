#include "bits/stdc++.h"

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string name;
    cin >> n;
    unordered_set<string> s;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        s.insert(name);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> name;
        cout << name << ":" << s.count(name) << '\n';
    }
}
