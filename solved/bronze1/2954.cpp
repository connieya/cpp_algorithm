#include "stdio.h"

char str[101];
int main()
{
    scanf("%[^\n]",str);
    for (int i = 0; str[i]; ++i) {
        printf("%c",str[i]);
        if(str[i]=='a' || str[i]=='e' || str[i]=='o' ||str[i]=='u' || str[i]=='i'){
            i+=2;
        }
    }
}