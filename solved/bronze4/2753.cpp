#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << ((n%4 == 0 && n%100 != 0) || n%400 == 0) ?  1 : 0;
}