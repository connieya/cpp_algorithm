#include "stdio.h"

char str[1001];
char alpha[27];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf(" %[^\n] %[^\n]", str,alpha);
        for (int i = 0; str[i] != 0; i++) {
            if (str[i] == ' ') {
                printf(" ");
            }else{
                printf("%c", alpha[str[i]-'A']);
            }
        }
        printf("\n");
    }
}