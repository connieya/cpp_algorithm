#include "bits/stdc++.h"

using namespace std;

bool comp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    cin >> n;
    vector<string> v;
    while (n--) {
        cin >> str;
        for (int i = 0; i < str.length();) {
            string tmp = "";
            while (i < str.length() && isdigit(str[i])) {
                tmp.push_back(str[i++]);
            }
            while (i < str.length() && !isdigit(str[i])) {
                i++;
            }
            if (tmp.length() == 0) {
                continue;
            }
            if (tmp[0] == '0') {
                while (tmp.size() && tmp.front() =='0'){
                    tmp.erase(tmp.begin());
                }
                if (tmp.size() == 0) {
                    tmp = '0';
                }
            }
            v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end(), comp);
    for (auto a: v) {
        cout << a << '\n';
    }
}