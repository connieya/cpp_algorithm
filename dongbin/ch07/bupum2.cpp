#include "stdio.h"

using namespace std;


int counting[1000000];
int main(void)
{
    int n ,m , tmp;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        counting[tmp]++;
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&tmp);
        if (counting[tmp]){
            printf("yes\n");
        }else {
            printf("no\n");
        }
    }
}