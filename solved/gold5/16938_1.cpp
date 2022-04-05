#include "bits/stdc++.h"
#define INF 1e8
using namespace std;
int arr[16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,L,R,X;
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i < (1<<N); ++i) {
        int num = i;
        int sum = 0;
        int lmin = INF;
        int lmax = 0;
        for (int j = 0; j < N; ++j) {
            if (num % 2){
                if (arr[j] > lmax){
                    lmax = arr[j];
                }
                if (arr[j] < lmin){
                    lmin = arr[j];
                }
                sum += arr[j];
            }
            num /=2;
        }
        if (sum >= L && sum <= R && lmax-lmin >= X){
            ans++;
        }
    }
    cout << ans;
    
}