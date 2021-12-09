#include "stdio.h"
#include "vector"

int main(void)
{
    int n , cnt ,pos;
    scanf("%d",&n);
    std::vector<int> is(n+1);
    std::vector<int> os(n+1);
    for (int i=1; i<=n; i++){
        scanf("%d",&is[i]);
    }
    for(int i=n; i>0; i--){
        cnt = is[i];
        for (int j=i; j<i+cnt; j++){
            os[j] = os[j+1];
        }
        os[i+cnt] = i;
    }
//    for (int i=n; i>=1; i--){
//        pos = i;
//        for (int i=1; i<=is[i]; i++){
//            os[pos] = os[pos+1];
//            pos++;
//        }
//        os[pos] = i;
//    }
    for (int i=1; i<=n; i++){
        printf("%d ",os[i]);
    }

}