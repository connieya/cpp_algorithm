#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n < 100){
        cout << n;
    }else {
        int answer = 99;
        for (int i = 100; i <= n; ++i) {
            answer += (i/100 - i/10%10 == i/10%10 - i%10);
        }
        cout << answer;
    }
}