#include "stdio.h"
#include "algorithm"
#include "vector"

long long reverse(long long n) {
    long long res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main(void) {
    int n;
    long long tmp;
    scanf("%d", &n);
    std::vector<long long > vector(n,0);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &tmp);
        vector[i] = reverse(tmp);
    }
    std::sort(vector.begin(),vector.end());
    for (int i = 0; i < n; ++i) {
        printf("%lld\n", vector[i]);
    }
}