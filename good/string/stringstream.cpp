#include "bits/stdc++.h"

using namespace std;

int main()
{
    string str = "hi my name is geonhee";
    string s;
    stringstream iss(str);
    while (iss >> s){
        cout << s << '\n';
    }
}