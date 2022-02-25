#include "bits/stdc++.h"

using namespace std;

int main()
{
    vector<int>  a = {1,3,2,3,2,3,2,3,1,2};
    set<int> s;
    for (int i = 0; i < a.size(); ++i) {
        s.insert(a[i]);
    }
    cout << s.size() << '\n';
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << '\n';
    for (auto x: s) {
        cout << x << ' ';
    }
    cout << '\n';
    if (s.find(3) == s.end()) { // 3이 set 자료구조에 없다면~
        cout << "3 is not in set";
    } else {
        cout << "3 is in set  : true";
    }
    cout <<'\n';
}