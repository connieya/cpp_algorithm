#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ,res =0;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> st;
        for (char ch : s) {
            if(!st.empty() && st.top() == ch){
                st.pop();
            }else {
                st.push(ch);
            }
        }
        if (st.empty()) {
            res++;
        }
    }
    cout << res;
}