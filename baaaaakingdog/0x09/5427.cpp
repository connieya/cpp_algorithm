#include "stdio.h"

char building[1000][1000];

int main(void) {
    int t, w, h;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &w, &h);
        for (int i = 0; i < h; ++i) {
            scanf("%s", building[i]);
        }
        for (int i = 0; i < h; ++i) {
            printf("%s\n", building[i]);
        }
        printf("\n");
    }

}
