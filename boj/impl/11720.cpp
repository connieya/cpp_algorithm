#include <cstdio>
int main()
{
    int n,x;
    int rst =0;
    scanf("%d",&n);
    while (n--){
        scanf("%1d",&x);
        rst+=x;
    }
    printf("%d\n",rst);
}