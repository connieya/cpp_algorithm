#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v.push_back(2);
    v.push_back(12);
    v.push_back(5);
    v.push_back(34);
    v.push_back(45);

    for (auto s: v) { // 2 , 12 , 5, 34 ,45
        cout << s << ' ';
    }
    cout << '\n';

    v.erase(v.begin());
    for (auto s: v) { // 12 , 5 , 34, 45
        cout << s << ' ';
    }
    cout << '\n';

    v.erase(v.begin()+2);

    for (auto s: v) { // 12 , 5 , 45
        cout << s << ' ';
    }
    cout << '\n';
}