#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str , bomb;
    cin >> str >> bomb;
    int len = str.length();
    int b_len = bomb.length();
    string ans;
    for (int i = 0; i < len; ++i) {
        if (ans.length() >= b_len){
            int s = b_len;
            string tmp = "";
            while (s--){
                 tmp.push_back(ans.back());
                 ans.pop_back();
            }
            reverse(tmp.begin(),tmp.end());
            if (tmp != bomb){
                ans += tmp;
            }
        }
        ans.push_back(str[i]);
    }
    string tmp;
    while (b_len--){
        tmp += ans.back();
        ans.pop_back();
    }
    reverse(tmp.begin(),tmp.end());
    if (tmp != bomb){
        ans += tmp;
    }
    if (ans.length() == 0){
        cout << "FRULA";
    }else{
        cout << ans;
    }
}