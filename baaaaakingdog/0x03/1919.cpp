#include "stdio.h"
#include "iostream"

int main(void)
{
    char s1[1001], s2[1001];
    int a[2][26] ={},ans=0;
    scanf("%s",s1);
    scanf("%s",s2);
    for (int i = 0; s1[i]; ++i) {
        a[0][s1[i]-'a']++;
    }
    for (int i = 0; s2[i]; ++i) {
        a[1][s2[i]-'a']++;
    }
    for (int i=0; i<26; i++){
        ans += abs(a[0][i]-a[1][i]);
    }
    printf("%d",ans);
}