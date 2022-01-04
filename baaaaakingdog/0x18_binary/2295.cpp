#include "stdio.h"
#include "algorithm"
#include "vector"

using namespace std;

int main(void) {
    int n, ans = -1;
    scanf("%d", &n);
    int arr[n];
    vector<int> two;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            two.push_back(arr[i] + arr[j]);
        }
    }
    sort(two.begin(), two.end());
    for (int j = n - 1; j >= 1; --j) {
        for (int k = 0; k < j; ++k) {
            if (binary_search(two.begin(), two.end(), arr[j] - arr[k])) {
                printf("%d", arr[j]);
                return 0;
            }
        }
    }
}