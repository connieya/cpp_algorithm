#include "bits/stdc++.h"

using namespace std;

int arr[] = {2, 5, 6, 9, 12, 21}; // size : 6

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << lower_bound(arr, arr + 6, 1) - arr << '\n'; // 0번째
    cout << lower_bound(arr, arr + 6, 4) - arr << '\n'; // 1번째
    cout << lower_bound(arr, arr + 6, 5) - arr << '\n'; // 1번째
    cout << lower_bound(arr, arr + 6, 6) - arr << '\n'; // 2번째
    cout << lower_bound(arr, arr + 6, 7) - arr << '\n'; // 2번째
    cout << lower_bound(arr, arr + 6, 8) - arr << '\n'; // 2번째
    cout << lower_bound(arr, arr + 6, 9) - arr << '\n'; // 3번째
    cout << lower_bound(arr, arr + 6, 10) - arr << '\n'; // 3번째
    cout << lower_bound(arr, arr + 6, 11) - arr << '\n'; // 3번째
    cout << lower_bound(arr, arr + 6, 12) - arr << '\n'; // 4번째
    cout << lower_bound(arr, arr + 6, 13) - arr << '\n'; // 5번째
    cout << lower_bound(arr, arr + 6, 22) - arr << '\n'; // 6번째
}