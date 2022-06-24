#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> s;
    s.insert(23);
    s.insert(13);
    s.insert(22);
    s.insert(523);
    s.insert(123);
    cout << s.count(1) << '\n';
    cout << s.count(11) << '\n';
    cout << s.count(13) << '\n';
    cout << s.count(523) << '\n';
}