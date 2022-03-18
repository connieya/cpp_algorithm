#include "bits/stdc++.h"

using namespace std;

int price[100001];
long long dis[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> dis[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    long long sum = 0;
    long long min_price = price[0];
    for (int i = 0; i < n; ++i) {
        if (min_price > price[i]) {
            min_price = price[i];
        }
        sum += min_price * dis[i];
    }
    cout << sum;
}