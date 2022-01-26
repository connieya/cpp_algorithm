#include "stdio.h"
using namespace std;

int arr[10001];

int main(void) {
    int n , tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        arr[tmp]++;
    }
    for (int i = 1; i <= 10000; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            printf("%d\n",i);
        }
    }
}