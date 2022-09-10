#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    vector<char> s;
    for(auto ch : a){
        s.push_back(ch);
        while (s.size() >= b.size() && string(s.begin()+s.size()-b.size() , s.end()) == b){
            for (int i = 0; i < b.size(); ++i) {
                s.pop_back();
            }
        }
    }
    cout << (s.size() ? string(s.begin(),s.end()) : "FRULA");
}