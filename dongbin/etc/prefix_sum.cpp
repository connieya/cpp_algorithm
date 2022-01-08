#include "bits/stdc++.h"

using namespace std;

int n = 10;
int arr[10] = {15, 35, 50, 10, 45, 70, 90, 100, 65, 800};
int prefix_sum[11];
int main(void)
{
    prefix_sum[0] = 0;
    for (int i = 1; i < 11; ++i) {
        prefix_sum[i] = prefix_sum[i-1] +arr[i-1];
    }
    for (int i = 0; i < 11; ++i) {
        cout << prefix_sum[i] << ' ';
    }
    cout << '\n';
    int a = 2 , b = 4; // 2~ 4 까지의 합
    cout << prefix_sum[b] - prefix_sum[a-1] << '\n';
     a = 5 , b = 9; // 5~ 9 까지의 합
    cout << prefix_sum[b] - prefix_sum[a-1] << '\n';

}