#include "bits/stdc++.h"

using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001];

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int lidx = start;
    int ridx = mid;
    for (int i = start; i < end; ++i) {
        if(ridx == end) tmp[i] = arr[lidx++];
        else if (lidx == mid) tmp[i] = arr[ridx++];
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for (int i = start; i < end; ++i) {
        arr[i] = tmp[i];
    }

}

void merge_sort(int start, int end) {
    if (start +1 == end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    merge_sort(0, n);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
}