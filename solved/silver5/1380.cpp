#include "stdio.h"

int main(void) {
    int n, scenario =1;
    while (1) {
        scanf("%d", &n);
        if (!n) {
            break;
        }
        char names[101][61];
        int lists[101] = {0,};
        int num;
        char buf;
        for (int i = 1; i <= n; i++) {
            scanf(" %[^\n]s", names[i]);
        }
        for (int i = 0; i < 2 * n - 1; ++i) {
            scanf("%d %c", &num, &buf);
            lists[num]++;
        }
        for (int i=1; i<=n; i++){
            if(lists[i] == 1){
                printf("%d %s\n",scenario++,names[i]);
                break;
            }
        }
    }
}