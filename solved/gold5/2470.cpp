#include "bits/stdc++.h"
#define MAX 100001

using namespace std;

int arr[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int lt = 0 , rt = n-1;
    int MIN = INT_MAX;
    while (lt < rt) {
        int sum = arr[lt]+arr[rt];
        if (abs(sum) < MIN){
            MIN = abs(sum);
            a = arr[lt];
            b = arr[rt];
        }
        if (sum > 0) {
            rt--;
        }else {
            lt++;
        }

    }
    cout << a << ' ' << b;

}