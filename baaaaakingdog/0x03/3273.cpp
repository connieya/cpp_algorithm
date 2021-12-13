#include "stdio.h"
#include "vector"

int num[1000001] = {0};
int check[1000001] = {0};

int main() {
    int n, value, x, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", num[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; ++i) {
        if (num[i] >= x || x-num[i] > 1000000) {
            continue;
        }
        if(x-num[i] <= 1000000 && check[x-num[i]]){
            cnt++;
        }
        check[num[i]] = 1;
    }
    printf("%d", cnt / 2);
}