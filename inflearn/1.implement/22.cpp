#include "stdio.h"
#include "vector"

int main(void) {
    int n, k, max = 0, answer = 0, i;
    scanf("%d %d", &n, &k);
    std::vector<int> a(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < k; i++) {
        answer += a[i];
    }
    max = answer;
    for (i=k; i<n; i++){
        answer = answer + a[i]-a[i-k];
        if(answer > max){
            max = answer;
        }
    }
    printf("%d", max);

}