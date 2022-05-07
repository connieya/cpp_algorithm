#include "bits/stdc++.h"

using namespace std;

int alpha[26];
int temp[26];
vector<string> v;
unordered_map<string,bool> mp;

void init() {
    for (int i = 0; i < 26; ++i) {
        temp[i] = alpha[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num, len = 0;
    char ch;
    string str;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ch >> num;
        alpha[ch - 'a'] = num;
        len += num;
    }

    cin >> str;
    for (int i = 0; i <= str.length() - len; ++i) {
        init();
        bool flag = true;
        string s = "";
        for (int j = i; j < len + i; ++j) {
            if (temp[str[j] - 'a'] > 0) {
                s.push_back(str[j]);
                temp[str[j] - 'a']--;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            v.push_back(s);
        }
    }

    cout << mp.size();

}