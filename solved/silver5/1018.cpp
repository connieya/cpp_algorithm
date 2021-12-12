#include "stdio.h"

#define min(a, b) a < b ? a : b

int main(void) {
    char board[51][51];
    int n, m, min = 32;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }
    for (int i = 0; i <= n - 8; ++i) {
        for (int j = 0; j <= m - 8; ++j) {
            int count = 0;
            for (int k = i; k < i + 8; ++k) {
                for (int l = j; l < j + 8; ++l) {
                    if ((k + l) % 2 == ((board[k][l] == 'W') ? 0 : 1)) { // 홀수 칸에는 무조건 B가 와야한다.
                        count++; // 그런데 W가 와면 다시 색칠하야한다.
                    }
                }
            }// 위의 식에서 홀 수칸에 무조건 B가 올 경우에만 고려했음
            count = min(count, 64 - count); // 홀수 칸에 W가 올 경우는 64-count임
            min = min(min, count);
        }
    }
    printf("%d", min);
}