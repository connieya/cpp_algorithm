#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string a ,b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int arr[2] = {0,};
        int diff = 0;
        int len = a.length();
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]){
                diff++;
                a[i] == '0' ? arr[0]++ : arr[1]++;
            }
        }
        arr[0] = min(arr[0],arr[1]);
        cout << diff-arr[0] << '\n';
    }
}