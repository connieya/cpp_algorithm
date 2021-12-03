#include "cstdio"
int n;
char str[51],c;
int main(){
    scanf("%d %s",&n,str);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; str[j]; ++j) {
            scanf(" %c",&c);
            str[j] = (str[j]-c) ? '?' : c;
        }
    }
    printf("%s",str);
}