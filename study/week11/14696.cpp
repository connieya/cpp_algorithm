#include "stdio.h"

int main(void)
{
    int n;
    scanf("%d" ,&n);
    char result[] = "ABD";
    while (n--) {
        int game_result[5] = {0};
        int a = 0;
        scanf("%d" , &a);
        for (int i=0; i<a; i++){
            int shape =0;
            scanf("%d",&shape);
            game_result[shape]++;
        }
        int b = 0;
        scanf("%d",&b);
        for (int i = 0; i < b; ++i) {
            int shape = 0;
            scanf("%d", &shape);
            game_result[shape]--;
        }
        int now = 2;
        for (int i = 4; i >=1; --i) {
            if(game_result[i] == 0) {
                continue;
            }
            now = game_result[i] < 0;
            break;

        }
        printf("%c \n" ,result[now]);
    }
}