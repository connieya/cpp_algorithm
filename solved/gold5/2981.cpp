#include "bits/stdc++.h"

using namespace std;

int arr[101];

int gcd(int a ,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

void print(int num , int i) {
    if (i*i > num) return;
    if (i*i == num) {
        cout << i << ' ';
        return;
    }
    if (num % i == 0) {
        cout << i << ' ';
        print(num,i+1);
        cout << num/i << ' ';
        return;
    }
    print(num , i+1);


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int g = arr[1]-arr[0];
    for (int i = 1; i < n - 1; ++i) {
        g = gcd(g,arr[i+1]-arr[i]);
    }
    print(g ,2);
    cout << g << ' ';
}