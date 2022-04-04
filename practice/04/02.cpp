#include "bits/stdc++.h"

using namespace std;

int alpha[26];
bool check[26];
string answer = "";

void solve(int len, string str) {
    for (int i = 0; i < len; ++i) {
        if (answer.empty()){
            answer+= str[i];
            check[str[i]-'A'] = true;
            continue;
        }
        if (check[str[i]-'A']){
            alpha[str[i]-'A']--;
            continue;
        }
        while (answer.back() > str[i] && alpha[answer.back()-'A'] > 1){
            check[answer.back()-'A'] = false;
            alpha[answer.back()-'A']--;
            answer.pop_back();
        }
        answer+= str[i];
        check[str[i]-'A'] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    for (int i = 0; str[i]; ++i) {
        if (str[i] >=97 && str[i] <= 122){
            str[i] -= 32;
        }
        alpha[str[i]-'A']++;
    }
    int len = str.length();
    solve(len,str);
    cout << answer;
}