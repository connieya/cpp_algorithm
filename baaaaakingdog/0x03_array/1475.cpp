#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a[10] = {0} , answer = 0;
    cin >> n;
    while (n){
        a[n%10]++;
        n /=10;
    }
    for (int i=0; i<10; i++){
        if(i==6 || i==9){
            continue;
        }
        answer = max(answer,a[i]);
    }
    printf("%d",max(answer,(a[6]+a[9]+1)/2));
}
