#include "bits/stdc++.h"

using namespace std;

bool erased[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, t;
    cin >> a >> t;
    vector<char> stack;
    bool flag = false;
    while (1){
        for (auto ch: t) {
            stack.push_back(ch);
            if (flag) continue;
            if (stack.size() >= a.size() && string(stack.begin() + stack.size() - a.size(), stack.end()) == a) {
                for (int i = 0; i < a.size(); ++i) {
                    stack.pop_back();
                }
                flag = true;
            }
        }
        if(!flag) break;
        reverse(a.begin(), a.end());
        vector<char> tmp;
        for (int i = stack.size() - 1; i >= 0; --i) {
            tmp.push_back(stack[i]);
            if (!flag) continue;
            if (tmp.size() >= a.size() && string(tmp.begin() + tmp.size() - a.size(), tmp.end()) == a) {
                flag = false;
                for (int j = 0; j < a.size(); ++j) {
                    stack.erase(stack.begin()+i);
                }
            }
        }
        if(flag) break;
        reverse(a.begin(),a.end());
        t = string(stack.begin(),stack.end());
        stack.clear();
    }

   cout << t;
}