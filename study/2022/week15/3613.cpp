#include "bits/stdc++.h"

using namespace std;
const string ERROR = "Error!";


bool isValid(char ch) {
    return isupper(ch) || ch == '_';
}

string solve(string str) {
    if (isValid(str[0])) return ERROR;
    int len = str.length();
    string ans = "";
    bool cpp = false, java = false;
    for (int i = 0; i < len; ++i) {
        if (cpp && java) return ERROR;
        if (str[i] == '_') {
            if (java) return ERROR;
            cpp = true;
            if (i + 1 == len || isValid(str[i + 1])) return ERROR;
            ans += (str[i + 1] - 32);
            i++;
        } else if (isupper(str[i])) {
            if (cpp) return ERROR;
            ans += "_";
            ans += (str[i] + 32);
            java = true;
        } else {
            ans += str[i];
        }
    }
//    if (!cpp && !java) return ERROR;
    if (cpp && java) return ERROR;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    cout << solve(str);
}