#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    list<int> L = {1 ,2 , 3};

    auto it = next(L.begin()); // *it == 2
    auto it2 = L.insert(it,10); // L = {1, 10 , 2, 3 } , *it2 == 10 , *it == 2

    it = prev(it); // *it == 10
    it = L.erase(it); // L = {1, 2, 3 } , *it == 2
}