#include "stdio.h"
int isGoldMinNum(int tmp){
    while (tmp > 0){
        if(tmp % 10 == 7 || tmp % 10 == 4){
            tmp = tmp/10;
        }else{
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 4; i--) {
        if(isGoldMinNum(i)){
            printf("%d",i);
            break;
        }
    }
}