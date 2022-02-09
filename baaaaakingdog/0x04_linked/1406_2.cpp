#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<char> L;
    stack<char> R;
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        L.push(str[i]);
    }
    int t;
    cin >> t;
    while (t-- ) {
        char op;
        cin >> op;
        if(op == 'L' && !L.empty()){
            R.push(L.top());
            L.pop(); continue;
        }
        if (op == 'D' && !R.empty()) {
            L.push(R.top());
            R.pop(); continue;
        }
        if (op == 'B' && !L.empty()){
            L.pop(); continue;
        }
        if (op == 'P'){
            char ch;
            cin >> ch;
            L.push(ch);
        }
    }
    while (!L.empty()){
        R.push(L.top());
        L.pop();
    }
    while (!R.empty()) {
        cout << R.top();
        R.pop();
    }
}