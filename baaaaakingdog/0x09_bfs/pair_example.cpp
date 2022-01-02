#include "bits/stdc++.h"

using namespace std;

int main() {
    pair<int, int> t1 = make_pair(10, 13);
    pair<int, int> t2 = {4, 6}; // c++ 11
    cout << t2.first << " " << t2.second << '\n';
    cout << (t2 < t1) << '\n';
}