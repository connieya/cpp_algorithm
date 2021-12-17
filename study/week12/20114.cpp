#include "stdio.h"

int main(void) {
    int N, H, W;
    scanf("%d %d %d", &N, &H, &W);
    char original[101];
    char str[1001];
    for (int i = 0; i < N; i++) {
        original[i] = '?';
    }
    original[N] = 0;
    while (H--) {
        scanf("%s", str);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < W; j++) {
                if (str[i * W + j] != '?') {
                    original[i] = str[i * W + j];
                    break;
                }
            }
        }
    }
    printf("%s",original);
}