#include "stdio.h"

int main()
{
    char a[101], b[101];
    int i, p =0;
    gets(a);
    for (i=0; a[i]!='\0'; i++){
        if(a[i]== ' '){
            continue;
        }
        if(a[i]>='A' && a[i] <='Z'){
            b[p++] = a[i]+32;
            continue;
        }
        b[p++] = a[i];
    }
    b[p] = '\0';
    printf("%s\n",b);
}