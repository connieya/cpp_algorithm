#include "bits/stdc++.h"

using namespace std;

int main()
{
    vector<int> v;
    vector<int> a;
    a.push_back(2);
    a.push_back(12);
    a.push_back(22);
    v = a;
    cout << v.size() << '\n';
    for (int j: v) {
        cout << j << '\n';
    }
}