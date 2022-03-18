#include "bits/stdc++.h"

using namespace std;

bool Prime[100000001];

void init(int n) {
    Prime[1] = true;
    for (int i = 2; i*i <= n; ++i) {
        if (Prime[i]) continue;
        for (int j = i*i; j <= n; j+=i) {
            Prime[j] = true;
        }
    }
}


bool isPalindrome(int num) {
    if (num < 10) return true;
    string str = to_string(num);
    string front;
    front = str;
    reverse(str.begin(),str.end());
    if (front == str) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a ,b;
    cin >> a  >> b;
    init(b);
    if (b > 10000000) {
        b = 10000000;
    }
    for (int i = a; i <= b; ++i) {
        bool isPal = isPalindrome(i);
        if (!isPal) continue;
        if (!Prime[i]){
            cout << i << '\n';
        }
    }
    cout << -1;
}