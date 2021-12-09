#include "stdio.h"

int main(void) {
    int year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}; // 0 ,1 ,2 ,3 ,4, 5, 6,
    int x, y;
    scanf("%d %d", &x, &y);
    int today = 0;
    for (int i = 0; i < x; i++) {
        today += year[i];
    }
    today += y;
    printf("%s", week[today % 7]);
}