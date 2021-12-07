#include "stdio.h"
#include "vector"

using namespace std;
int main(void)
{
    int n , rank;
    scanf("%d",&n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        rank = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[j]>=arr[i]) {
                rank++;
            }
        }
        printf("%d ",rank);
    }
}