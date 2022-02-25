#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    stack<char> S;
    int sum = 0;
    int num = 1;
    for (char ch : str) {
        if (ch == '(') {
            int n = S.top()-48;
            num *= n;
            S.pop();
            sum += S.size();
            while (!S.empty()){
                S.pop();
            }
        } else if(ch == ')') {
            int cnt = 0;
            while (S.top() != '('){
                S.pop();
                cnt++;
            }
            S.pop();
            num *=cnt;
            sum += num;
            num = 1;
        }else {
            S.push(ch);
        }
    }
    cout << sum+S.size();
}