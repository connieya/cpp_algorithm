#include "stdio.h"

int main(void)
{
    int n;
    scanf("%d",&n);
    char s1[1001],s2[1001];
    while (n--){
        int a[26] = {0};
        int flag = 1;
        scanf("%s %s",s1 ,s2);
        for (int i = 0; s1[i]; ++i) {
            a[s1[i]-'a']++;
        }
        for (int i = 0; s2[i]; ++i) {
            a[s2[i]-'a']--;
        }
        for(int c : a){
            if(c){
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("Possible\n");
        }else{
            printf("Impossible\n");
        }
    }
}