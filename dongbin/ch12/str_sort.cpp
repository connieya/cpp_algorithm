#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    cin >> input;
    int len = input.length();
    vector<char> v;
    int num = 0;
    for (int i = 0; i < len; ++i) {
        if (isdigit(input[i])) {
            num += input[i]-'0';
            continue;
        }
        v.push_back(input[i]);
    }
    sort(v.begin(),v.end());
    for (char c: v) {
        cout << c;
    }
    if (num != 0) {
        cout << num;
    }
}