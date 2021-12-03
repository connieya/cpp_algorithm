#include "stdio.h"

int main(void) {
    int n, m, e, count = 0, answer = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &e);
        if (e > m) {
            count++;
        } else {
            count = 0;
        }
        if(count > answer){
            answer = count;
        }
    }
    if (answer == 0) {
        printf("%d",-1);
    } else {
        printf("%d", answer);
    }
}