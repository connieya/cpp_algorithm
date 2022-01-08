#include "bits/stdc++.h"

using namespace std;

int ar[] = {1, 2, 3, 2, 5};
int n = 5;
int target = 5;

int main(void) {
    int ans = 0, rt = 0;
    int sum = 0;

    for (int lt = 0; lt < n; ++lt) {
        while (sum < target && rt < n) {
            sum += ar[rt];
            rt++;
        }
        if (sum == target) {
            ans++;
        }
        sum -= ar[lt];
    }
    printf("%d",ans);
}