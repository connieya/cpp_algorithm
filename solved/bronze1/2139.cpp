#include "stdio.h"

int main(void) {
    int day, month, year, answer;
    int dayOfYear[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (1) {
        scanf("%d %d %d", &day, &month, &year);
        answer = 0;
        if (day == 0 && month == 0 && year == 0) {
            break;
        }

        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            // 윤년
            for (int i = 0; i < month; i++) {
                answer += dayOfYear2[i];
            }
        } else {
            for (int i = 0; i < month; ++i) {
                answer += dayOfYear[i];
            }
        }
        printf("%d\n", answer + day);
    }
}