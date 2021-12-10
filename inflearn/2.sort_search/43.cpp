#include "stdio.h"
#include "vector";

int main() {
    int n, m, tmp, start = 1, end = 0 ,res;
    scanf("%d %d", &n, &m);
    std::vector<int> arr;
    for (int i=0; i<n; i++) {
        scanf("%d", &tmp);
        arr.push_back(tmp);
        end += tmp;
    }
    while (start<=end){
        int mid =(start+end)/2;
        for(int i=0; i<n; i++) {

        }
    }
}