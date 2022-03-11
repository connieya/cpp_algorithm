#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    do {
        cout << str << '\n';
    } while (next_permutation(str.begin(),str.end()));

}