#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<string , int> ch;
    map<string , int> ::iterator it;
    for (int i = 0; i < n; ++i) {
        char str[100];
        cin >> str;
        ch[str]++;
    }
    for(it = ch.begin(); it != ch.end(); it++) {
        cout << it -> first << ' ' << it ->second << '\n';
    }
    /*
    7
    bag
    cat
    str
    apple
    str
    book
    cat
    bag

     */
}