#include "bits/stdc++.h"

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<char ,int> ch;
    map<char ,int>::iterator it;
    char a[100];
    // ex) -> adsdsdadsddsd
    cin >> a;
    for (int i = 0; a[i]; ++i) {
        ch[a[i]]++;
    }

    for(it = ch.begin(); it != ch.end(); it++) {
        cout << it -> first << ' ' << it ->second << '\n';
    }
}