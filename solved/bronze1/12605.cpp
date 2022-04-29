#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ,num = 0;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin , str);
        stringstream iss(str);
        vector<string> v;
        while (iss >> str){
            v.push_back(str);
        }
        int len = v.size();
        cout << "Case #"<<++num<<": ";
        for (int i = len-1; i >=0; --i) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
}