#include "stdio.h"

int arr[10][10] , b[10];
int main(void)
{
    int n,sum =0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&b[i]);
    }
    for (int i=0; i<n; i++){
        for (int j = 0; j < n; ++j) {
            arr[j][i] = b[i];
        }
    }
    for (int i = n-1; i >=0; --i) {
        scanf("%d",&b[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i][j] > b[i]){
                arr[i][j] = b[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += arr[i][j];
        }
    }
    printf("%d",sum);
}