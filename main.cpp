#include "bits/stdc++.h"

using namespace std;

bool alpha[28];

void dfs(int L, int n, int start) {
    if (L == n) {
        for (int i = 0; i <= 26; i++) {
            if (alpha[i]) {
                cout << 'a'-i << ' ';
            }
        }
        cout << '\n';
        return;
    }


    for (int i = start + 1; i <= 26; i++) {
        alpha[L] = true;
        dfs(L + 1, n, i);
        alpha[L] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 5;
//    dfs(0, n, 0);
    vector<string> v;
    v.push_back("dsds");
    v.push_back("dss");
    vector<string> str;
    str =v;
    for(string s : str){
        cout << s << '\n';
    }




}