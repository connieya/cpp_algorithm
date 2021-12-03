#include "stdio.h"
int main()
{
    int a,b,people,paper;
    scanf("%d %d",&a,&b);
    people = a*b;
    for (int i = 0; i < 5; ++i) {
        scanf("%d",&paper);
        printf("%d ",paper-people);
    }
}