#include "bits/stdc++.h"

using namespace std;

bool isPrime(int n) {
    if (n<=1) return false;
    for (int i = 2; i*i <=n ; ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,min;
    cin >> n >> m;
    int sum = 0;
    bool flag = false;
    for (int i = n; i <= m; ++i) {
        if (isPrime(i)) {
            if (!flag){
                min = i;
            }
            flag = true;
            sum += i;
        }
    }
    if (flag){
        cout << sum << '\n' << min;
    }else {
        cout <<-1;
    }
}