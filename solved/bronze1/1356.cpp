#include "stdio.h"
#include "string.h"
char a[15];

int multiple(int start , int end){
    int value =1;
    for(int i=start; i<=end; i++){
        value *= (a[i]-'0');
    }
    return value;
}

int main()
{
    scanf("%s",a);
    for (int i=0; i< strlen(a)-1; i++){
        if(multiple(0,i) == multiple(i+1, strlen(a)-1)){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}