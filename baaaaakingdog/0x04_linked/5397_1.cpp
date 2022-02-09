#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        list<char> l;
        string str;
        cin >> str;
        auto p = l.begin();
        for(char ch : str) {
            if(ch== '<'){
                if(p != l.begin()) {
                    p--;
                }
            } else if(ch == '>'){
                if(p != l.end()) {
                    p++;
                }
            } else if (ch == '-') {
                if(p != l.begin()) {
                    p--;
                    p = l.erase(p);
                }
            }else {
                l.insert(p,ch);
            }
        }
        for(auto c : l) {
            cout << c;
        }
        cout << '\n';
    }
}