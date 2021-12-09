#include "stdio.h"
#include "iostream"
int main() {
    int t, s = 0, b = 0 ,n,m , sMax =-1, bMax=-1;
    char str[4];
    scanf("%d",&t);
    while (t--){
        scanf("%d %d",&n,&m);
        sMax = -1;
        while (n--){
            scanf("%d",&s);
            sMax = std::max(s,sMax);
        }
        bMax = -1;
        while (m--){
            scanf("%d",&b);
            bMax = std::max(b,bMax);
        }
        puts(bMax>sMax ? "B" :"S");
    }
}