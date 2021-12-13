#include "stdio.h"

int students[7][2];

int main() {
    int n, k, sex, grade, cnt = 0;
    scanf("%d %d", &n, &k);
    while (n--) {
        scanf("%d %d", &sex, &grade);
        students[grade][sex]++;
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            cnt += students[i][j] / k;
            if (students[i][j] % k) {
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}