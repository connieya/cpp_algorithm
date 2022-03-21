#include "bits/stdc++.h"

using namespace std;

string S,T;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> T;
    int len = S.size();
    while (T.size() > len) {
        if (T[T.size()-1] == 'A'){
            T = T.substr(0,T.size()-1);
        }else {
            T = T.substr(0,T.size()-1);
            reverse(T.begin(),T.end());
        }
    }
    if (S== T){
        cout << 1;
    }else {
        cout << 0;
    }
}