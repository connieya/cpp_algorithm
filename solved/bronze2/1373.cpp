#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string binary;
    cin >> binary;
    if ( binary.length() % 3 == 2){
        binary = '0'+binary;
    } else if (binary.length() % 3 == 1){
        binary = "00"+binary;
    }
    int len = binary.length();
    for (int i = 0; i < len; i+=3) {
        int num = (binary[i]-'0')*4 +(binary[i+1]-'0')*2 + (binary[i+2]-'0')*1;
        cout << num;
    }

}