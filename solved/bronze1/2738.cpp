#include "stdio.h"

int main(void)
{
    int n,m ,value;
    int arr[100][100];
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&value);
            printf("%d ",(value+arr[i][j]));
        }
        printf("\n");
    }
}