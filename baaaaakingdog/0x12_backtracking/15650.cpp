#include "stdio.h"
#include "algorithm"
#include "vector"

using namespace std;

int n, m;
vector<int> arr;


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        arr.push_back(i < m ? 0 : 1);
    }
    do {
        for (int i = 0; i < n; ++i) {
            if (!arr[i]){
                printf("%d ",i+1);
            }
        }
        printf("\n");
    } while (next_permutation(arr.begin(),arr.end()));

}