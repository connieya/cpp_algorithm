#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long S , sum = 0;
    int cnt = 0;
    cin >> S;
    while (S >= sum){
        sum += ++cnt;
    }
    if (sum > S) cnt--;
    cout << cnt;

}