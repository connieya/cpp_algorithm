#include "bits/stdc++.h"

using namespace std;

int a[] = {1, 3, 5, 12, 34};
int b[] = {2, 4, 6, 8, 9, 11, 45, 56};
int arr[13];

int main(void) {
    int ai = 0;
    int bi = 0;
    int idx = 0;
    while (ai < 5 && bi < 8) {
        if (a[ai] < b[bi]) {
            arr[idx] = a[ai++];
        } else {
            arr[idx] = b[bi++];
        }
        idx++;
    }
    while (ai < 5) {
        arr[idx++] = a[ai++];
    }
    while (bi < 8) {
        arr[idx++] = b[bi++];
    }
    for (int i = 0; i < 13; ++i) {
        cout << arr[i] << ' ';
    }
}