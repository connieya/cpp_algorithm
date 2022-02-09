#include "bits/stdc++.h"

using namespace std;

double alpha[26];
double Stack[101];
int idx = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    string str;
    stack<double> S;
    cin >> str;
    for (int i = 0; i < t; ++i) {
        cin >> alpha[i];
    }
    for (char ch: str) {
        if (ch >= 'A' && ch <= 'Z') {
            double num = alpha[ch - 'A'];
            Stack[idx++] = num;
        } else {
            if (ch == '+') {
                Stack[idx - 2] += Stack[idx - 1];
            }
            if (ch == '-') {
                Stack[idx - 2] -= Stack[idx - 1];
            }
            if (ch == '*') {
                Stack[idx - 2] *= Stack[idx - 1];
            }
            if (ch == '/') {
                Stack[idx - 2] /= Stack[idx - 1];
            }
            idx--;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << Stack[0];

}