#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str = "problem";
    cout << (str.find("ro") != string::npos) << '\n';
    cout << (str.find("pro") != string::npos) << '\n';
    cout << (str.find("ob") == string::npos) << '\n';
    cout << (str.find("proble") == string::npos) << '\n';
    cout << (str.find("blem") == string::npos) << '\n';
    cout << (str.find("prosle") == string::npos) << '\n';
    cout << (str.find("roblem") == string::npos) << '\n';

}