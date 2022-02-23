#include "bits/stdc++.h"

using namespace std;

long long alpha[10];
bool checked[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        int len = input.length()-1;
        checked[input[0]-'A'] = true;
        long long pow = 1;
        for (int i=len; i>=0; i--){
            alpha[input[i]-'A'] += pow;
            pow *= 10;
        }
    }
    int zero = 0;
    for (int i = 0; i < 10; ++i) {
        if (!checked[i]){
            zero = i;
            break;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (!checked[i] && alpha[zero] > alpha[i]) {
            zero = i;
        }
    }
    alpha[zero] = 0;
    sort(alpha,alpha+10);
    int index = 9;
    long long ans = 0;
    for (int i = 9; i >= 0; --i) {
        ans += alpha[i]*index;
        index--;
    }
    cout << ans;
}