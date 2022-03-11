#include "bits/stdc++.h"

using namespace std;

int arr[500001];

int gcb(int a , int b) {
    if (b == 0 ) return a;
    return gcb(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> x;
    double sum = 0;
    double cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (gcb(arr[i],x) == 1){
            sum += arr[i];
            cnt++;
        }
    }
    cout << sum /cnt;
}