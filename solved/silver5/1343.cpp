#include "bits/stdc++.h"
#define A "AAAA"
#define B "BB"

using namespace std;

vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int len = str.size();
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '.'){
            if (cnt % 2 == 1){
                cout << -1;
                return 0;
            }
            if (cnt == 0){
                ans.push_back(".");
                cnt = 0;
                continue;
            }

            for (int j = 0; j < cnt /4; ++j) {
                ans.push_back(A);
            }
            if (cnt % 4 > 0) {
                ans.push_back(B);
            }
            cnt = 0;
            ans.push_back(".");
        }else {
            cnt++;
        }
    }

    if (cnt % 2 == 1){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < cnt / 4; ++i) {
        ans.push_back(A);
    }
    if (cnt % 4 > 0){
        ans.push_back(B);
    }
    for (string s: ans) {
        cout << s;
    }

}