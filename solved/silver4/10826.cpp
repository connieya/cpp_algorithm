#include "bits/stdc++.h"

using namespace std;


string add(string a, string b) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string a = "0";
    string b = "1";
    if (n == 0) {
        cout << a;
        exit(0);
    }
    if (n == 1) {
        cout << b;
        exit(0);
    }
    string result;
    for (int i = 2; i < n; ++i) {
        result = add(a,b);
        a = b;
        b = result;
    }
    cout << result;

}