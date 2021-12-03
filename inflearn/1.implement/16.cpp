#include "stdio.h"
#include "algorithm"
int main(void)
{
    int alpha[52] = {0};
    char str1[101];
    char str2[101];
    bool flag = true;
    scanf("%s",str1);
    scanf("%s",str2);
    for (int i = 0; str1[i]!=0; ++i) {
        if(str1[i]> 96){
            alpha[str1[i]-71]++;
        }else{
            alpha[str1[i]-65]++;
        }
    }
    for (int i = 0; str2[i]!=0; ++i) {
        if(str2[i]> 96){
            alpha[str2[i]-71]--;
        }else{
            alpha[str2[i]-65]--;
        }
    }
    for (int i = 0; i < 52; ++i) {
        if(alpha[i] != 0){
            printf("NO");
            exit(0);
        }
    }
        printf("YES");
}