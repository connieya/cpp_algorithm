#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str = "AEIOU";

    string temp = "AAAAEIAO";
    for(int i=0; i<temp.length(); i++){
        cout << str.find(temp[i]) << '\n';
    }
}