#include "stdio.h"

int main(void)
{
    int n , answer = 9210000 , num1, num2;
    scanf("%d",&n);
    char draws[5][7][50];
    for (int i=0; i<n; i++){
        for (int j=0; j<5; j++){
            for (int k=0; k<7; k++) {
                scanf(" %c",&draws[j][k][i]);
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            int count =0;
            for (int x=0; x<5; x++){
                for (int y=0; y<7; y++){
                    count += (draws[x][y][i] != draws[x][y][j]);
                    if(count > answer){
                        break;
                    }
                }
            }
            if(count < answer){
                answer = count;
                num1 = i+1;
                num2 = j+1;
            }
        }
    }
    printf("%d %d",num1,num2);
    return 0;
}