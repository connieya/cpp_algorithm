#include "bits/stdc++.h"

using namespace std;

int d[8001] = {0,};
int arr[500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num;
    cin >> n;
    double sum = 0;
    cin >> num;
    arr[0] = num;
    sum += num;
    d[num+4000]++;
    int MAX = num, MIN = num;
    for (int i = 1; i < n; ++i) {
        cin >> num;
        arr[i] = num;
        sum += num;
        d[num + 4000]++;
        if (num > MAX) MAX = num;
        if (num < MIN) MIN = num;
    }
    sort(arr, arr + n);
    int v = 0;
    int ans = 0;
    bool flag = true;
    for (int i = 0; i <= 8000; ++i) {
        if (d[i] > v) {
            v = d[i];
            ans = i-4000;
            flag = true;
        } else if (d[i] == v && flag) {
            flag = false;
            v = d[i];
            ans = i-4000;
        }
    }
    double avg;
    avg = sum /n;
    avg = round(avg);

    cout << (int)avg << '\n';
    cout << arr[(n-1) / 2] << '\n';
    cout << ans << '\n';
    cout << MAX - MIN << '\n';

}