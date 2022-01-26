#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    long long arr[68];
    arr[0] =1 , arr[1] =1 , arr[2]= 2 ,arr[3] =4;
    for (int i = 4; i <= 67; ++i) {
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    }
    while (t-- ){
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
}