#include "stdio.h"

int main(void) {
    int N, x, y, answer = 0;
    scanf("%d", &N);
    int a[100][100] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if(!a[x+j][y+k]){
                    a[x+j][y+k] =1;
                    answer++;
                }
            }
        }
    }
    printf("%d",answer);
}