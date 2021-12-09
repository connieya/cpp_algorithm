#include "stdio.h"
#include "vector"

int main(void) {
    int n, m , a , pos;
    scanf("%d %d", &n, &m);
    std::vector<int> arr(n);
    for (int i=0; i<m; i++){
        scanf("%d",&a);
        pos = -1;
        for (int j=0; j<n; j++){
            if (arr[j] == a){
                pos = j;
                break;
            }
        }
        if (pos == -1){
            for (int i=n-1; i>0; i--){
                arr[i] = arr[i-1];
            }

        }else {
            for (int i=pos; i>0; i--){
                arr[i] = arr[i-1];
            }
        }
        arr[0] = a;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
}