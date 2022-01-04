#include "stdio.h"
#include "algorithm"
using namespace std;

bool isUsed[500002];

int main(void) {
    int n, m, size;
    scanf("%d %d", &n, &m);
    int a[n], tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    size = n;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &tmp);
        if (binary_search(a, a + n, tmp)) {
            isUsed[tmp] = true;
            size--;
        }
    }
    printf("%d\n", size);
    if (size) {
        for (int i = 0; i < n; ++i) {
            if (!isUsed[a[i]]) {
                printf("%d ", a[i]);
            }
        }
    }
}