#include "stdio.h"
#include "vector"
#include "algorithm"

int main()
{
    int n,m ,i1 =0 ,i2 = 0 , i3 =0;
    scanf("%d",&n);
    std::vector<int> a(n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end());
    scanf("%d",&m);
    std::vector<int> b(n);
    for (int i=0; i<m; i++){
        scanf("%d",&b[i]);
    }
    sort(b.begin(),b.end());
    std::vector<int> c(n>m ? m: m);
    while (i1 < n && i2<m){
        if(a[i1] < b[i2]){
            i1++;
        } else if(b[i2] < a[i1]){
            i2++;
        }else{
           c[i3++] = a[i1];
           i1++;
           i2++;
        }
    }
    for (int i=0; i<i3; i++){
        printf("%d ",c[i]);
    }
}