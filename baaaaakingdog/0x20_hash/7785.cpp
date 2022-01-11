#include "bits/stdc++.h"

using namespace std;

int main(void) {
    int n;
    char name[6], op[6];
    cin >> n;
    unordered_set<string> s;

    while (n--) {
        cin >> name >> op;
        if (op[0] == 'e') {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (auto x: ans) {
        cout << x << '\n';
    }
}