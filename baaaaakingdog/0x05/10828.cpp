#include "bits/stdc++.h"
#include "stack"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num;
    string cmd;
    cin >> n;
    stack<int> stack;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            stack.push(num);
            continue;
        }
        if (cmd == "top") {
            if (stack.empty()) {
                cout << -1<<'\n';
                continue;
            }
            cout << stack.top()<<'\n';
            continue;
        }
        if (cmd == "size") {
            cout << stack.size()<<'\n';
            continue;
        }
        if(cmd == "pop") {
            if (stack.empty()) {
                cout << -1<<'\n';
                continue;
            }
            cout << stack.top()<<'\n';
            stack.pop();
            continue;
        }
        if (cmd == "empty"){
           cout << (int)stack.empty() <<'\n';
            continue;
        }
    }
}