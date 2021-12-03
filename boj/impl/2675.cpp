#include "cstdio"
int t,r;
char s[21];
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d %s",&r,&s);
        for (int i = 0; s[i]; ++i) {
            for (int j = r; j--;) {
                putchar(s[i]);
            }
        }
        puts("");
    }
    return 0;
}