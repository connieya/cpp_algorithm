#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    regex r(R"((100+1+|01)+)");
    string str;
    cin >> str;
    regex_match(str,r) ? cout << "SUBMARINE" : cout << "NOISE";
}