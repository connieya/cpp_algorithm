#include <iostream>
#include "stdio.h"
#include "vector"
using namespace::std;
int main(void)
{
    int n,k ,pos =0 , bp = 0, cnt = 0;
    scanf("%d %d",&n,&k);
    vector<int> prince(n+1);
    while (bp < n-1){
        pos++;
        if (pos > n){
            pos = 1;
        }
        if(prince[pos] == 0) {
            cnt++;
            if(cnt == k){
                prince[pos] =1;
                cnt = 0;
                bp++;
            }
        }
    }
    for (int i=1; i<=n; i++){
        if(!prince[i]){
            printf("%d",i);
            break;
        }
    }

}