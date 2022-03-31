#include "bits/stdc++.h"

using namespace std;
int arr[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        double n,cnt = 0;
        cin >> n;
        double avg = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            avg += arr[i];
        }
        avg /= n;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > avg){
                cnt++;
            }
        }
        cout.setf(ios::fixed , ios::floatfield);
        cout.precision(3);
        cout << cnt/n*100<<"%"<<'\n';
    }
}