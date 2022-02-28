#include "bits/stdc++.h"

using namespace std;

bool isPalindrome(string a) {
    int len = a.length();
    for (int i = 0; i < len/2; ++i) {
        if (a[i] != a[len-1-i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string S;
    cin >> S;
    int len = S.length();
    int answer = S.length()*2 -1;
    for (int j = 0; j < len; ++j) {
        string tmp = S.substr(j);
        if (isPalindrome(tmp)) {
            answer = S.length()+j;
            break;
        }
    }
    cout << answer;
}