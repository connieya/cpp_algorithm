#include "stdio.h"

int main()
{
    int n , i, a[100] , b[100];
    scanf("%d" ,&n);
    for (i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for (i=0; i<n; i++){
        scanf("%d",&b[i]);
    }
    for (i=0; i<n; i++){
        if(a[i] == b[i]){
            printf("%s \n","D");
            continue;
        } else if(a[i]==3 && b[i] == 1){
            printf("%s \n","B");
            continue;
        } else if(a[i]==1 && b[i] == 3){
            printf("%s \n","A");
            continue;
        }

        printf("%s \n",a[i] > b[i] ? "A" : "B");
    }
}