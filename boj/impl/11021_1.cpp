#include <cstdio>

int a,b,t,i;

int main() {
    scanf("%d" ,&t);
    for(; i<t; i++){
        scanf("%d%d",&a,&b);
        printf("Case #%d: %d\n",i+1,a+b);
    }
}