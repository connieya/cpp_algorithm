#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    string ans = "";
    for (int i = 0; i < str.length(); ++i) {
        ans += str[i];
        if (ans.length() >= 4){
            char a = ans.back(); ans.pop_back();
            char b =ans.back(); ans.pop_back();
            char c = ans.back(); ans.pop_back();
            char d = ans.back(); ans.pop_back();
            string now = "";
            now +=d;
            now +=c;
            now +=b;
            now +=a;
            if (now == "PPAP"){
                ans += "P";
            }else {
                ans += now;
            }
        }
    }
    if (ans == "P"  || ans == "PPAP" ){
        cout << "PPAP";
    }else {
        cout << "NP";
    }
}