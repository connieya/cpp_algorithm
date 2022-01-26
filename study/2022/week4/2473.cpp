#include "bits/stdc++.h"

using namespace std;

long long arr[5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , xs, s, l;
    long long MIN = 214700000000000;
    vector<int> ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; ++i) {
        int init = arr[i];
        int lt = i + 1;
        int rt = n - 1;
        while (lt < rt) {
            long long sum = init + arr[lt] + arr[rt];
            if (abs(sum) < MIN) {
                MIN = abs(sum);
                xs = init;
                s = arr[lt];
                l = arr[rt];
            }
            if (sum > 0) {
                rt--;
            } else if (sum < 0) {
                lt++;
            } else {
                i = n;
                break;
            }

        }
    }
    cout << xs << ' ' << s << ' ' << l;
}