#include "stdio.h"

bool prime[200001];
int main()
{
    prime[1] = true;
    for (int i = 2; i*i <= 200000; ++i) {
        if(prime[i]){
            continue;
        }
        for (int j = i+i; j <= 200000; j+=i) {
            prime[j] = true;
        }
    }
    int n ,answer =0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        if(!prime[i]){
            answer++;
        }
    }
    printf("%d",answer);
}