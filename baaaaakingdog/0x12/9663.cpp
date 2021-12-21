#include "stdio.h"

int cnt;
int n;
bool isVisited1[40];
bool isVisited2[40];
bool isVisited3[40];

void nQueen(int L) {
    if (L == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (isVisited1[i] || isVisited2[i + L] || isVisited3[L - i + n - 1]) continue;
        isVisited1[i] = true;
        isVisited2[i + L] = true;
        isVisited3[L-i+n-1] = true;
        nQueen(L + 1);
        isVisited1[i] = false;
        isVisited2[i + L] = false;
        isVisited3[L-i+n-1] = false;
    }

}

int main(void) {
    n;
    scanf("%d", &n);
    nQueen(0);
    printf("%d", cnt);
}