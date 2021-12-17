#include "bits/stdc++.h"

using namespace std;

bool checkValid(stack<char> stack, char ch) {
    if (stack.empty()) {
        return false;
    }
    if (ch == ']' && stack.top() != '[') {
        return false;
    }
    if (ch == ')' && stack.top() != '(') {
        return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        string a;
        getline(cin, a);
        if (a == ".") {
            break;
        }
        stack<char> stack;
        bool isValid = true;
        for (auto c: a) {
            if (c == '(' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == ']') {
                if (checkValid(stack, c)) {
                    stack.pop();
                } else {
                    isValid = false;
                    break;
                }
            }
        }
        if(!isValid || !stack.empty()){
            cout << "no" << "\n";
        }else{
            cout << "yes" << "\n";
        }
    }
}