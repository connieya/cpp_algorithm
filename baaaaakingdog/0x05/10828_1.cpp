#include "stdio.h"

int stack[10000];
int pos;

int main(void) {
    int n ,x;
    scanf("%d", &n);
    while (n--) {
        char str[7];
        scanf("%s", str);
        if (str[0] == 'p') {
            if (str[1] == 'u') {
                scanf("%d",&x);
                stack[pos++] = x;
                continue;
            }
            if (str[1] == 'o') {
                if (!pos) {
                    printf("%d\n", -1);
                } else {
                    pos--;
                    printf("%d\n", stack[pos]);
                }

            }
        } else if (str[0] == 't') {
            if (!pos) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", stack[pos-1]);
            }
        }else if(str[0] == 'e'){
            if (!pos) {
                printf("%d\n", 1);
            } else {
                printf("%d\n",0);
            }
        }else {
            printf("%d\n",pos);
        }
    }
}