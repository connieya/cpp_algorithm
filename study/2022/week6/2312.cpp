#include "bits/stdc++.h"

using namespace std;

void func(int num){
    for(int i=2; i*i<=num; i++){
        if(num % i == 0){
            cout << i << ' ';
            int cnt = 0;
            while (num % i == 0){
                cnt++;
                num /= i;
            }
            cout << cnt << '\n';
        }
    }
    if(num != 1) {
        cout << num << ' ' << 1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        func(n);
    }
}