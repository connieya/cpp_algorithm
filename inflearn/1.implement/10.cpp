#include "stdio.h"

int digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void) {
    int n, num, sum, max = -1, answer;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        sum = digit_sum(num);
        if (sum > max) {
            max = sum;
            answer = num;
        } else if (sum == max) {
            if (num > answer) {
                answer = num;
            }
        }
    }
    printf("%d", answer);
}