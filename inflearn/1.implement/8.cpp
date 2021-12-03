#include "stdio.h"
int main()
{
    char str[100];
    int cnt = 0;
    scanf("%s",&str);
    for (int i = 0; str[i]!='\0'; ++i) {
        if(str[i] =='('){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt <0){
            break;
        }
    }
    if(cnt ==0){
        printf("YES\n");
    }else {
        printf("NO\n");
    }
}