#include "bits/stdc++.h"

using namespace std;


bool is_group_word(bool alpha[26] , string str){
    int len = str.length();
    for (int i = 0; i < len - 1; ++i) {
        alpha[str[i]-'a'] = true;
        if (str[i] != str[i+1] && alpha[str[i+1]-'a']) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--){
        string str;
        cin >> str;
        bool alpha[26] = {false,};
        if (is_group_word(alpha,str)){
            ans++;
        }
    }
    cout << ans;
}