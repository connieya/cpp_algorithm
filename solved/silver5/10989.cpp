#include "bits/stdc++.h"

using namespace std;
int tmp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        tmp[num]++;
    }
    for (int i = 1; i <= 10000; ++i) {
        while (tmp[i]){
            cout << i << '\n';
            tmp[i]--;
        }
    }
}