#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> strList;
    int n, minLength = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        strList.push_back(input);
        minLength = min(minLength, int(input.size()));
    }
    string res;
    int len = strList.size();
    for (int i = 0; i < minLength; ++i) {
        string tmp;
        for (int j = 0; j < len; ++j) {
           tmp += strList[j][i];
        }
        if (std::count(tmp.begin(), tmp.end(), tmp[0]) == n) {
            res += strList[0][i];
        }else {
            break;
        }
    }
    cout << res << '\n';
}