#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    getline(cin, str);
    string tmp;
    int n = str.size();
    for (int i = 0; i < n;) {
        if (str[i] == ' '){
            i++;
            continue;
        }
        if (str[i] == '<') {
            int j = i;
            while (j < n && str[j] != '>') {
                j++;
            }
            i = j + 1;
        }
        int j = i;
        while (j < n && str[j] != ' ' && str[j] != '<') {
            j++;
        }
        reverse(str.begin() + i, str.begin() + j);
        i = j;
    }
    cout << str;
}