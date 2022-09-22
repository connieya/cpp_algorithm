#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int money;
    cin >> money;
    int price[14] = {0,};
    int a = money;
    int b = money;
    int j = 0, s = 0;
    vector<int> stack;
    for (int i = 0; i < 14; ++i) {
        cin >> price[i];
        j += a / price[i];
        a = a % price[i];
        stack.push_back(price[i]);
        if (stack.size() >= 4) {
            int len = stack.size();
            int m1 = stack[len - 4];
            int m2 = stack[len - 3];
            int m3 = stack[len - 2];
            if (m1 < m2 && m2 < m3) {
                if (s) {
                    b = s * price[i] + b;
                    s = 0;
                }
            } else if (m1 > m2 && m2 > m3) {
                s += b / price[i];
                b = b % price[i];
            }
        }
    }
    a = a + price[13] * j;
    b = b + s * price[13];
    cout << (a == b ? "SAMESAME" : a > b ? "BNP" : "TIMING");
}