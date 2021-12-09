#include "stdio.h"

int main(void)
{
    int map[100][100] = {0};
    int x1,y1,x2,y2 , answer =0;
    for (int i=0; i<4; i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for (int i=x1; i<x2; i++){
            for (int j = y1; j < y2; ++j) {
                if(!map[i][j]){
                    map[i][j] =1;
                    answer++;
                }
            }
        }
    }
    printf("%d",answer);
}