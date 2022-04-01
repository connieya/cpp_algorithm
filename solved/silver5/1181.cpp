#include "bits/stdc++.h"

using namespace std;

string arr[20001];
string tmp[20001];

void merge(string arr[], int lt, int mid, int rt) {
    int p1 = lt, p2 = mid + 1, p3 = lt;
    while (p1 <= mid && p2 <= rt) {
        if (arr[p1].length() < arr[p2].length()) {
            tmp[p3++] = arr[p1++];
        } else if (arr[p1].length() == arr[p2].length()) {
            if (arr[p1].compare(arr[p2]) > 0){
                tmp[p3++] = arr[p2++];
            }else {
                tmp[p3++] = arr[p1++];
            }

        } else {
            tmp[p3++] = arr[p2++];
        }
    }
        while (p1 <= mid) {
            tmp[p3++] = arr[p1++];
        }
        while (p2 <= rt) {
            tmp[p3++] = arr[p2++];
        }
        for (int i = lt; i <= rt; ++i) {
            arr[i] = tmp[i];
        }
    }

    void mergeSort(int lt, int rt) {
        if (lt < rt) {
            int mid = (lt + rt) / 2;
            mergeSort(lt, mid);
            mergeSort(mid + 1, rt);
            merge(arr, lt, mid, rt);
        }
    }

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        mergeSort(0, n - 1);
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] != arr[i + 1]) {
                cout << arr[i] << '\n';
            }
        }
        cout << arr[n - 1];
    }