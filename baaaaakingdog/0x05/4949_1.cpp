#include "bits/stdc++.h"

using namespace std;
char S[101];
int idx;

char top() {
    return S[idx-1];
}
void pop() {
    if(idx > 0){
        idx--;
    }
}
bool isEmpty() {
    return  idx == 0;
}

bool check(char ch) {
    if (isEmpty()) return false;

    if(ch == ']' && top() == '[') return true;

    if (ch ==')' && top() == '(') return true;

    return false;
 }
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        string str;
        string ans = "yes";
        getline(cin, str);
        idx = 0;
        if (str == ".") break;
        for (char ch: str) {
            if (ch == '[') {
                S[idx++] = ch;
                continue;
            }
            if (ch == '(') {
                S[idx++] = ch;
                continue;
            }
            if (ch == ']') {
                if (check(ch)) {
                    pop();
                }else {
                    ans = "no";
                    break;
                }
            }
            if (ch == ')') {
                if (check(ch)) {
                    pop();
                }else {
                    ans = "no";
                    break;
                }
            }
        }
        if (!isEmpty()){
            ans = "no";
        }
        cout << ans <<'\n';
    }
}