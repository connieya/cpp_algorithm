#include "stdio.h"

using namespace std;

int main(void) {
    int n, res = -1;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int lt = 0;
    int rt = arr[n - 1];
    while (lt <= rt) {
        int mid = (lt + rt) / 2;
        if (mid == arr[mid]) {
            res = mid;
        }
        if (arr[mid] > mid) { // 중간 값이 중간 점보다 클 경우 오른쪽 부분은 볼 필요가 없다.
            rt = mid-1; // 오른쪽은 중간 값 중간 점 모두 증가하기 때문에 같은 수가 나올리가 없기 때문
        }else{ // 중간 값이 중간 점보다 작을 경우 왼쪽 부분은 탐색할 필요가 없다.
            lt = mid +1; //오름차순 정렬이기 때문에 왼쪽 부부은 값이 작아지기 때문에 같은 점이 있을리가 없다.
        }
    }
    printf("%d",res);
}