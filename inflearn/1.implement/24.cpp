#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    int n, pre, now, i ,sub;
    scanf("%d", &n);
    scanf("%d", &pre);
    vector<int> arr(n);
    for (i = 1; i < n; i++) {
        scanf("%d", &now);
        sub = abs(now - pre);
        if(sub > 0 && sub < n && arr[sub] == 0){
            arr[sub] = 1;
        }else{
            printf("NO\n");
            return 0;
        }
        pre = now;
    }
    printf("YES\n");
}