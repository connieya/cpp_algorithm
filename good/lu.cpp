#include "bits/stdc++.h"

using namespace std;

int l_bound(int arr[], int st, int end, int target) {
    while (st < end) {
        int mid = (st + end) / 2;
        if (arr[mid] >= target) {
            end = mid;
        } else {
            st = mid + 1;
        }
    }
    return end;
}

int u_bound(int arr[], int st, int end, int target) {
    while (st < end) {
        int mid = (st + end) / 2;
        if (arr[mid] > target) {
            end = mid;
        } else {
            st = mid + 1;
        }
    }
    return end;
}


int main() {
    int arr[] = {-2, -1, 2, 4, 12, 17, 21, 43};
    cout << lower_bound(arr, arr + 8, 4) - arr << '\n'; // 3번째 인덱스
    cout << upper_bound(arr, arr + 8, 4) - arr << '\n'; // 4번째 인덱스
    cout << l_bound(arr,0,8,4) << '\n'; // 3번쩨 인덱스
    cout << u_bound(arr,0,8,4) << '\n'; // 4번째 인덱스
}