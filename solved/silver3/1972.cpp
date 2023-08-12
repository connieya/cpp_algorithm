#include "bits/stdc++.h"

using namespace std;

bool solve(string str) {
    int n = str.size();
    for(int dir=1; dir<=n-1; dir++) {
        set<string> set;
        for(int j=0; j<n-dir; j++){
            string s;
            s+= str[j];
            s+= str[j+dir];
            if(set.find(s) != set.end()) return false;
            set.insert(s);
        }
    }


    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    while (true) {
        cin >> str;
        if(str == "*") break;
        if(solve(str)) {
            cout << str << " is surprising." << "\n";
        }else {
            cout << str << " is NOT surprising." << '\n';
        }
    }
}