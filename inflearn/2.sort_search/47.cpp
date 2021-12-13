#include "stdio.h"

int arr[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(void)
{
    int n, cnt = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool flag = true;
            for (int k = 0; k < 4; ++k) {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(nx >=0 && nx < n && ny >=0 && ny< n) {
                    if(arr[i][j] <= arr[nx][ny]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}