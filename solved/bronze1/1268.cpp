#include "stdio.h"
int main()
{
    int a;
    int arr[1001][6];
    scanf("%d",&a);
    for (int i=1; i<=a; i++){
        for (int j=1; j<=5; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max = -1;
    int answer = 0;
    for (int i=1; i<=a; i++){
        int count = 0;
        for (int j=1; j<=a; j++){
            for (int k=1; k<=5; k++){
                if(arr[i][k]== arr[j][k]) {
                    count++;
                    break;
                }
            }
        }
        if(count > max) {
            max = count;
            answer = i;
        }
    }
    printf("%d",answer);
}