#include "stdio.h"

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char woman[5][5];
char tmp;
int main(void)
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%c",&tmp);
            printf("%c",tmp);
        }
        printf("\n");
    }

}