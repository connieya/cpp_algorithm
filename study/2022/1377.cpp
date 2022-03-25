#include "bits/stdc++.h"
#define MAX 500001
using namespace std;

int arr[MAX];

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
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < n - i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                flag = true;
                int tmp = arr[j+1];
                arr[j+1] =  arr[j];
                arr[j] = tmp;
            }
        }
        if (!flag){
            cout << i+1;
            break;
        }
    }

}