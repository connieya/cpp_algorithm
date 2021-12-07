#include "stdio.h"

int main(void) {
    char str[10];
    int i ,c = 0 ,h , pos;
    scanf("%s",str);
    if(str[1] =='H'){
        c = 1;
        pos = 2;
    }else {
        for (i=1; str[i]!='H'; i++){
            c = c*10 +(str[i]-48);
        }
        pos = i+1;
    }
    if(str[pos] == 0){
        h = 1;
    }
    for(i = pos; str[i] !=0; i++){
        h = h*10 +(str[i]-48);
    }
    printf("%d",12*c+h);
}