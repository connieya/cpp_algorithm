#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.txt","rt",stdin);
    string str;
    cin >> str;
    int len = str.length();
    string res = "";
    stack<char> S;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ')') {
            string tmp = "";
            while (S.top() != '(') {
                tmp += S.top();
                S.pop();
            }
            S.pop();
            reverse(tmp.begin(), tmp.end());
            string num;
            if (S.empty()) num = "1";
            else {
                while (!S.empty()) {
                    num += S.top();
                    S.pop();
                }
            }
            reverse(num.begin(), num.end());
            int n = stoi(num);
            for (int j = 0; j < n; ++j) {
                res += tmp;
            }
        } else {
            S.push(str[i]);
        }
    }
    cout << res;

}