#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
//    freopen("C:\\c_cpp_study\\c_cpp_algorithm\\inflearn\\1.implement\\input.txt", "rt", stdin);
    int i, j, n, tmp;
    scanf("%d", &n);
    vector<int> ch(n + 1);
    for (i = 2; i <= n; i++) {
        tmp = i;
        j = 2;
        while (tmp > 1) {
            if (tmp % j == 0) {
                tmp = tmp/j;
                ch[j]++;
            } else {
                j++;
            }
        }
    }
    printf("%d! = ",n);
    for (i = 2;  i<=n ; i++) {
        if(ch[i] != 0){
            printf("%d ",ch[i]);
        }
    }
}
