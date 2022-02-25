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
        bool flag = true;
        for (int j = 0; j < len-1; ++j) {
            if (strList[j][i] != strList[j+1][i]){
                flag = false;
                break;
            }
        }
        if (flag) {
            res += strList[0][i];
        }else {
            break;
        }
    }
    cout << res << '\n';
}