#include "stdio.h"
#include "string.h"

int main() {
    int a[10], b[10], aScore =0 , bScore = 0;
    char win[3] = "D";
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < 10; ++i) {
        if (a[i] == b[i]) {
            aScore++, bScore++;
            continue;
        } else if (a[i] > b[i]) {
            aScore += 3;
            strcpy(win, "A");
        } else {
            bScore += 3;
            strcpy(win, "B");
        }
    }
    printf("%d %d \n",aScore,bScore);
    if (aScore == bScore) {
        printf("%s", win);
    } else if (aScore > bScore) {
        printf("A");
    } else {
        printf("B");
    }
}